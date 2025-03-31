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

    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void ExecuteAttack(Entity* attacker, Entity* target);
    int CalculateDamage(Entity* attacker, Entity* target);
};
