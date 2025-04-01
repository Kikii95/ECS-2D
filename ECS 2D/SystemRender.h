#pragma once
#include "System.h"
#include "ComponentRender.h"
#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SystemRender : public System {
public:
    SystemRender();

	SystemType GetType() const override { return SystemType::UI; }
    void Update(float dt, const std::vector<Entity*>& entities) override;
};
