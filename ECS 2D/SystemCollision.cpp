#include "SystemCollision.h"
#include "ComponentTransform.h"
#include "ComponentCollider.h"
#include "ComponentProjectile.h"
#include "ComponentPhysics.h"
#include "ActionDatabase.h"
#include <iostream>
#include "SystemAction.h"
// #include "GameModeManager.h" 

SystemCollision::SystemCollision() {}

void SystemCollision::SetExplorationMode(bool active) {
    explorationMode = active;
}

void SystemCollision::Update(float dt, const std::vector<Entity*>& entities) {
    if (!explorationMode) return; 

    for (size_t i = 0; i < entities.size(); ++i) {
        Entity* a = entities[i];

        if (a->GetComponent<ComponentProjectile>()) continue; //TO DO : suppr car pas de component collider sur les projectil a verifier

        auto* colA = a->GetComponent<ComponentCollider>();
        auto* trA = a->GetComponent<ComponentTransform>();
        if (!colA || !trA) continue;

        for (size_t j = i + 1; j < entities.size(); ++j) {
            Entity* b = entities[j];
            if (b->GetComponent<ComponentProjectile>()) continue;

            auto* colB = b->GetComponent<ComponentCollider>();
            auto* trB = b->GetComponent<ComponentTransform>();
            if (!colB || !trB) continue;

            sf::FloatRect rectA(trA->GetPosition(), colA->GetColliderSize());
            sf::FloatRect rectB(trB->GetPosition(), colB->GetColliderSize());

            if (rectA.intersects(rectB)) {
				std::cout << "[Collision] Collision détectée entre " << a->GetID() << " et " << b->GetID() << "\n";
                ResolveCollision(a, b);
            }
        }
    }
}

void SystemCollision::ResolveCollision(Entity* a, Entity* b) {
    auto* colA = a->GetComponent<ComponentCollider>();
    auto* colB = b->GetComponent<ComponentCollider>();
    if (!colA || !colB) return;

    Entity* actor = a;
    Entity* target = b;
    ColliderType type = colB->GetColliderType();

    if (colA->GetColliderType() != ColliderType::Solid) {
        actor = b;
        target = a;
        type = colA->GetColliderType();
    }

    auto* physics = actor->GetComponent<ComponentPhysics>();
    if (!physics) return;

    switch (type) {
    case ColliderType::Solid: {
        std::cout << "[Collision] Obstacle : détection au sol / rollback si besoin.\n";

		if (physics->IsOnGround()) break;

        auto* transform = actor->GetComponent<ComponentTransform>();
        auto* physics = actor->GetComponent<ComponentPhysics>();
        if (!transform) break;

        sf::Vector2f prev = transform->GetPreviousPosition();
        sf::Vector2f curr = transform->GetPosition();
        sf::Vector2f delta = curr - prev;

        if (curr.y > target->GetComponent<ComponentTransform>()->GetPosition().y + colB->GetColliderSize().y / 2) {
            physics->SetIsGrounded(true);
            break;
        }
        
        sf::Vector2f rollback = curr;
        if (std::abs(delta.x) > 0.001f) rollback.x = prev.x;
        if (std::abs(delta.y) > 0.001f) rollback.y = prev.y;

        transform->SetPosition(prev);
		physics->SetAcceleration({ 0.f, 0.f });

        if (physics) {
            if (std::abs(delta.x) > 0.001f) physics->SetVelocityX(0.f);
            if (delta.y < 0.0f) physics->SetVelocityY(0.f);
        }
        
        break;
    }


    case ColliderType::Mob: {
        std::cout << "[Collision] Mob : lancement d’un combat.\n";
        // À faire : GameModeManager::EnterCombat(actor, target);
        std::cout << " Simulation du combat entre " << actor->GetID() << " et " << target->GetID() << "\n";
        break;
    }

    //case ColliderType::Object: {
    //    std::cout << "[Collision] Objet : action 'interact'.\n";
    //    const ActionData* action = ActionDatabase::Get().GetAction("interact_lever"); // exemple générique
    //    if (action) {
    //        GameEngine::GetInstance().GetSystemManager().GetSystem<SystemAction>()->ExecuteAction(actor, action);
    //    }
    //    break;
    //}

    //case ColliderType::Gatherable: {
    //    std::cout << "[Collision] Ressource : action 'gather'.\n";
    //    const ActionData* action = ActionDatabase::Get().GetAction("gather_wood"); // exemple générique
    //    if (action) {
    //        GameEngine::GetInstance().GetSystemManager().GetSystem<SystemAction>()->ExecuteAction(actor, action);
    //    }
    //    break;
    //}
    }
}
