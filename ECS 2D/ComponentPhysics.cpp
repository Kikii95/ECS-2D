#include "ComponentPhysics.h"
#include "ComponentTransform.h"

ComponentPhysics::ComponentPhysics(Entity* entity)
    : Component(entity), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {
}

void ComponentPhysics::ApplyForce(const sf::Vector2f& force) {
    acceleration += force;
}

void ComponentPhysics::ApplyGravity(float gravity) {
    if (affectedByGravity) {
        acceleration.y += gravity;
    }
}

void ComponentPhysics::Jump(float force) {
    if (isOnGround) {
        velocity.y = -force;
        isOnGround = false; 
    }
}

sf::Vector2f ComponentPhysics::GetVelocity() const {
    return velocity;
}

void ComponentPhysics::SetVelocity(const sf::Vector2f& v) {
    velocity = v;
}

sf::Vector2f ComponentPhysics::GetAcceleration() const {
    return acceleration;
}

void ComponentPhysics::SetAcceleration(const sf::Vector2f& a) {
    acceleration = a;
}

bool ComponentPhysics::IsOnGround() const {
    return isOnGround;
}

void ComponentPhysics::SetIsGrounded(bool state) {
    isOnGround = state;
}

bool ComponentPhysics::IsAffectedByGravity() const {
    return affectedByGravity;
}

void ComponentPhysics::SetAffectedByGravity(bool state) {
    affectedByGravity = state;
}

void ComponentPhysics::UpdatePhysics(float dt, sf::Vector2f gravity) {
    velocity += acceleration * dt;

    acceleration = { 0.0f, 0.0f };

    if (affectedByGravity && !isOnGround) {
        acceleration.y = gravity.y;
    }
    else {
        acceleration.y = 0.0f;
    }

    velocity += acceleration * dt;

    velocity.x *= 0.98f;
    velocity.y *= 0.98f;

    float maxFallSpeed = 5000.0f;
    if (velocity.y > maxFallSpeed) {
        velocity.y = maxFallSpeed;
    }

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (transform) {
        transform->MoveBy(velocity * dt);

        float windowHeight = 720.0f - 50; //TODO :Degager cette offset
        if (transform->GetPosition().y >= windowHeight) {
            transform->SetPosition({ transform->GetPosition().x, windowHeight });
            velocity.y = 0.0f;
            isOnGround = true;
        }
        else {
            isOnGround = false; 
        }
    }
}
