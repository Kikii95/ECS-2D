#include "SystemCollision.h"
#include "ComponentPhysics.h"
#include "ComponentTransform.h"
#include "ComponentHealth.h"
#include "ComponentProjectile.h"
#include "ComponentTag.h"
#include <iostream>

void SystemCollision::Update(float dt, const std::vector<Entity*>& entities) {
    for (size_t i = 0; i < entities.size(); ++i) {
        ComponentCollider* colliderA = entities[i]->GetComponent<ComponentCollider>();
        if (!colliderA || !colliderA->IsActive()) continue;

        ComponentTransform* transformA = entities[i]->GetComponent<ComponentTransform>();
        if (!transformA) continue;

        for (size_t j = i + 1; j < entities.size(); ++j) { 
            ComponentCollider* colliderB = entities[j]->GetComponent<ComponentCollider>();
            if (!colliderB || !colliderB->IsActive()) continue;

            ComponentTransform* transformB = entities[j]->GetComponent<ComponentTransform>();
            if (!transformB) continue;

            if (colliderA->CheckCollision(colliderB)) {
                std::cout << "[INFO] Collision détectée entre Entity " << entities[i]->GetID()
                    << " et Entity " << entities[j]->GetID() << std::endl;

                HandleProjectileCollision(entities[i], entities[j]);
                HandleProjectileCollision(entities[j], entities[i]);

                HandleWallCollision(entities[i], entities[j]);
                HandleWallCollision(entities[j], entities[i]);

                HandleEntityCollision(entities[i], entities[j]);
            }
        }
    }
}

void SystemCollision::HandleProjectileCollision(Entity* projectile, Entity* target) {
    ComponentProjectile* proj = projectile->GetComponent<ComponentProjectile>();
    if (!proj) return;

    proj->DestroyProjectile(target);
}

void SystemCollision::HandleWallCollision(Entity* entityA, Entity* entityB) {
    ComponentTag* tagA = entityA->GetComponent<ComponentTag>();
    ComponentTag* tagB = entityB->GetComponent<ComponentTag>();

    bool isWallA = tagA && tagA->GetTag() == "WALL";
    bool isWallB = tagB && tagB->GetTag() == "WALL";

    if (isWallA && !isWallB) {
        entityB->GetComponent<ComponentTransform>()->MoveBy(-entityB->GetComponent<ComponentCollider>()->GetOverlap(entityA->GetComponent<ComponentCollider>()));
    }
    else if (isWallB && !isWallA) {
        entityA->GetComponent<ComponentTransform>()->MoveBy(-entityA->GetComponent<ComponentCollider>()->GetOverlap(entityB->GetComponent<ComponentCollider>()));
    }
}

void SystemCollision::HandleEntityCollision(Entity* entityA, Entity* entityB) {
    ComponentCollider* colliderA = entityA->GetComponent<ComponentCollider>();
    ComponentCollider* colliderB = entityB->GetComponent<ComponentCollider>();

    if (colliderA->IsTrigger() || colliderB->IsTrigger()) return; 

    sf::Vector2f overlap = colliderA->GetOverlap(colliderB);
    ResolveCollision(entityA, entityB, overlap);
}

void SystemCollision::ResolveCollision(Entity* entityA, Entity* entityB, const sf::Vector2f& overlap) {
    ComponentTransform* transformA = entityA->GetComponent<ComponentTransform>();
    ComponentTransform* transformB = entityB->GetComponent<ComponentTransform>();

    if (!transformA || !transformB) return;

    transformA->MoveBy(-0.5f * overlap);
    transformB->MoveBy(0.5f * overlap);

    ComponentPhysics* physicsA = entityA->GetComponent<ComponentPhysics>();
    ComponentPhysics* physicsB = entityB->GetComponent<ComponentPhysics>();

    if (physicsA) physicsA->SetVelocity({ 0, 0 });
    if (physicsB) physicsB->SetVelocity({ 0, 0 });
}
