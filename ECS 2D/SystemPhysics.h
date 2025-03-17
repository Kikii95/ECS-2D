#pragma once
#include "System.h"

class SystemPhysics : public System {
private:
    sf::Vector2f gravity = { 0.0f, -9.81f }; // Gravité en 2D (vers le bas)

public:
    void Update(float dt, const std::vector<Entity*>& entities) override;
};
