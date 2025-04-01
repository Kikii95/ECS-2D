#pragma once
#include "System.h"
#include <string>

class SystemWeapon : public System {
public:
    SystemWeapon();

    SystemType GetType() const override { return SystemType::Reactive; }

    int CalculateDamage(Entity* attacker, Entity* target);

    void Update(float dt, const std::vector<Entity*>&) override {}
};
