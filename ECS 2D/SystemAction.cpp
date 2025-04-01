#include "SystemAction.h"
#include "ComponentInventory.h"
#include "ComponentHealth.h"
#include "SystemBuffDebuff.h"
#include "EffectDatabase.h"
#include <iostream>

SystemAction::SystemAction() {}

void SystemAction::ExecuteAction(Entity* entity, const ActionData& action) {
    std::cout << "[SystemAction] Action déclenchée : " << action.name << std::endl;

    switch (action.type) {
    case ActionType::Use: {
        std::cout << " Utilisation d’un objet : " << action.itemId << std::endl;

        if (!action.effectId.empty()) {
            GameEngine::GetInstance().GetSystemManager().GetSystem<SystemBuffDebuff>()->ApplyEffect(entity, action.effectId);
            std::cout << " Effet appliqué : " << action.effectId << std::endl;
        }

        auto* inv = entity->GetComponent<ComponentInventory>();
        if (inv) {
            inv->RemoveItem(action.itemId, 1);
        }
        break;
    }

    case ActionType::Gather: {
        std::cout << " Récolte ciblée : " << action.targetType << std::endl;

        auto* inv = entity->GetComponent<ComponentInventory>();
        if (inv) {
            std::string resourceId = action.targetType; 
            inv->AddItem(ItemInstance(resourceId, action.value));
            std::cout << " Ajout de " << action.value << " x " << resourceId << std::endl;
        }
        break;
    }

    case ActionType::Inspect: {
        std::cout << " Inspection de la zone (" << action.targetType << ")" << std::endl;
		// TO DO : add logic for inspection
        break;
    }

    case ActionType::Interact: {
        std::cout << " Interaction avec : " << action.targetType << std::endl;
		// TO DO : add logic for interaction
        break;
    }

    default:
        std::cout << " Type d’action inconnu ou non géré." << std::endl;
        break;
    }
}
