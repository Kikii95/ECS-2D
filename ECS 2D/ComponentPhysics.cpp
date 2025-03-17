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

void ComponentPhysics::UpdatePhysics(float dt) {
    velocity += acceleration * dt;
    acceleration = { 0.0f, 0.0f };

    if (affectedByGravity && !isOnGround) {
        velocity.y += 9.81f * dt; 
    }

    velocity.x *= 0.99f;
    velocity.y *= 0.99f;

    if (velocity.y > 0 && isOnGround) {
        velocity.y = 0.0f;
    }

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (transform) {
        transform->MoveBy(velocity * dt);
    }
}
