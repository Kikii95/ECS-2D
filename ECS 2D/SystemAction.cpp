#include "SystemAction.h"
#include <iostream>

SystemAction::SystemAction() {}

void SystemAction::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* state = entity->GetComponent<ComponentState>();
        auto* actionComp = entity->GetComponent<ComponentAction>();
        if (!state || !actionComp) continue;

        if (state->GetState() != EntityState::ACTION) continue;

        const ActionData* action = actionComp->GetActionByName(state->GetStateName());
        if (!action) continue;

        ExecuteAction(entity, *action);

        state->SetState(EntityState::WAITING); 
    }
}

void SystemAction::ExecuteAction(Entity* entity, const ActionData& action) {
    std::cout << "[SystemAction] Action déclenchée : " << action.name << std::endl;

    if (action.type == ActionType::Heal) {
        auto* health = entity->GetComponent<ComponentHealth>();
        if (health) {
            health->Heal(action.value); 
        }
    }
    else if (action.type == ActionType::Buff) {
        auto* buff = entity->GetComponent<ComponentBuffDebuff>();
        if (buff) {
            BuffEffect effect(action.name, action.value, 3, true, false);
            buff->AddEffect(effect);
        }
    }
    else if (action.type == ActionType::Attack) {
        std::cout << "[SystemAction] Attaque déclenchée (redirect to Combat)." << std::endl;
    }
}
