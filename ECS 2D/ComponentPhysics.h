#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>

class ComponentTransform;

class ComponentPhysics : public Component {
public:
    ComponentPhysics(Entity* entity);

    void ApplyForce(const sf::Vector2f& force);
    void ApplyGravity(float gravity);
    void Jump(float force);

    sf::Vector2f GetVelocity() const;
    void SetVelocity(const sf::Vector2f& velocity);

    sf::Vector2f GetAcceleration() const;
    void SetAcceleration(const sf::Vector2f& acceleration);

    bool IsOnGround() const;
    void SetIsGrounded(bool state);

    bool IsAffectedByGravity() const;
    void SetAffectedByGravity(bool state);

    void UpdatePhysics(float dt, sf::Vector2f gravity);

private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    bool isOnGround = false;
    bool affectedByGravity = true;
};
