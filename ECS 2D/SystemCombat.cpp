#include "SystemCombat.h"
#include <iostream>

SystemCombat::SystemCombat() {}

void SystemCombat::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* state = entity->GetComponent<ComponentState>();
		auto* ai = entity->GetComponent<ComponentAI>();
        if (!state || state->GetState() != EntityState::ATTACKING) continue;

        Entity* target = ai->GetTarget(); 

        if (target) {
            ExecuteAttack(entity, target);
            state->SetState(EntityState::WAITING);
        }
    }
}

void SystemCombat::ExecuteAttack(Entity* attacker, Entity* target) {
    auto* health = target->GetComponent<ComponentHealth>();
    if (!health) return;

    int dmg = CalculateDamage(attacker, target);
    health->TakeDamage(dmg);

    std::cout << "Attaque ! Dégâts infligés : " << dmg << std::endl;

    auto* buff = attacker->GetComponent<ComponentBuffDebuff>();
    if (buff) {
        for (const auto& effect : buff->GetActiveEffects()) {
            if (!effect.isBuff) {
                auto* targetBuff = target->GetComponent<ComponentBuffDebuff>();
                if (targetBuff) {
                    targetBuff->AddEffect(effect);
                }
            }
        }
    }
}

int SystemCombat::CalculateDamage(Entity* attacker, Entity* target) {
    int atk = 0;
    int def = 0;

    if (auto* stats = attacker->GetComponent<ComponentStats>())
        atk += stats->GetStat("strength");

    if (auto* weapon = attacker->GetComponent<ComponentWeapon>())
        atk += weapon->GetDamage();

    if (auto* stats = target->GetComponent<ComponentStats>())
        def += stats->GetStat("defense");

    int raw = atk - def;
    return std::max(1, raw); 
}
