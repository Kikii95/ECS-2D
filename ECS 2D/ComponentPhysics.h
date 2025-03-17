#pragma once
#include <SFML/System.hpp>
#include "Component.h"

class ComponentPhysics : public Component {
private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    bool isOnGround = false;
    bool affectedByGravity = true;

public:
    ComponentPhysics(Entity* entity);

    void ApplyForce(const sf::Vector2f& force);
    void ApplyGravity(float gravity);
    void Jump(float force);
    void UpdatePhysics(float dt);

    sf::Vector2f GetVelocity() const;
    void SetVelocity(const sf::Vector2f& v);

    sf::Vector2f GetAcceleration() const;
    void SetAcceleration(const sf::Vector2f& a);

    bool IsOnGround() const;
    void SetIsGrounded(bool state);

    bool IsAffectedByGravity() const;
    void SetAffectedByGravity(bool state);
};
