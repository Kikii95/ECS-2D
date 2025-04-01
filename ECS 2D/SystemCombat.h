#pragma once
#include "System.h"
#include "ComponentCombat.h"
#include "ComponentAI.h"
#include "ComponentState.h"
#include "ComponentWeapon.h"
#include "ComponentHealth.h"
#include "ComponentStats.h"
#include "ComponentBuffDebuff.h"

class SystemCombat : public System {
public:
    SystemCombat();

    SystemType GetType() const override { return SystemType::TurnBased; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void ExecuteAttack(Entity* attacker, Entity* target);
    int CalculateDamage(Entity* attacker, Entity* target);
    void ApplyWeaponEffect(Entity* attacker, Entity* target, const std::string& effectId);
};
