#pragma once
#include "System.h"
#include "ComponentHealth.h"
#include "ComponentState.h"
#include <vector>

class SystemHealth : public System {
public:
    SystemHealth();

	SystemType GetType() const override { return SystemType::TurnBased; }
    void Update(float dt, const std::vector<Entity*>& entities) override;
};
