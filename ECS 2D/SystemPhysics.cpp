#include "SystemPhysics.h"
#include "ComponentPhysics.h"
#include "ComponentTransform.h"
#include <iostream>

void SystemPhysics::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        ComponentPhysics* physics = entity->GetComponent<ComponentPhysics>();
        if (!physics) continue;

        physics->SetAcceleration({ 0.0f, 0.0f });

        if (physics->IsAffectedByGravity() && !physics->IsOnGround()) {
            physics->AddAcceleration(gravity);
        }

        physics->AddVelocity(physics->GetAcceleration() * dt);

        sf::Vector2f velocity = physics->GetVelocity();
        velocity.x *= 0.98f;
        velocity.y *= 0.98f;

        const float maxFallSpeed = 5000.0f;
        if (velocity.y > maxFallSpeed) velocity.y = maxFallSpeed;

        physics->SetVelocity(velocity);

        ComponentTransform* transform = entity->GetComponent<ComponentTransform>();
        if (transform) {
            transform->MoveBy(velocity * dt);

			float groundY = 720.0f - 50.0f; //TO DO : Remove this offset (generalize)
            if (transform->GetPosition().y >= groundY) {
                transform->SetPosition({ transform->GetPosition().x, groundY });
                velocity.y = 0.0f;
                physics->SetVelocity(velocity);
                physics->SetIsGrounded(true);
            }
            else {
                physics->SetIsGrounded(false);
            }
        }

    }
}

