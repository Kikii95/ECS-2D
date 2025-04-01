#pragma once
#include "System.h"

class SystemCamera : public System {
public:
    SystemCamera();

    void Update(float dt, const std::vector<Entity*>& entities) override;
    SystemType GetType() const override { return SystemType::UI; }
};
