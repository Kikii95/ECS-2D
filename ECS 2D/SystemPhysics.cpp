#include "SystemPhysics.h"
#include "ComponentPhysics.h"
#include "ComponentTransform.h"
#include <iostream>

void SystemPhysics::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        ComponentPhysics* physics = entity->GetComponent<ComponentPhysics>();
        if (!physics) continue;

        physics->UpdatePhysics(dt);

        ComponentTransform* transform = entity->GetComponent<ComponentTransform>();
        if (transform) {
            transform->MoveBy(physics->GetVelocity() * dt);
        }
    }
}
