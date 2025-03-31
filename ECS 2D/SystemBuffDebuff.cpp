#include "SystemBuffDebuff.h"
#include <iostream>

SystemBuffDebuff::SystemBuffDebuff() {}

void SystemBuffDebuff::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* buffComp = entity->GetComponent<ComponentBuffDebuff>();
        if (!buffComp) continue;

        for (const auto& effect : buffComp->GetActiveEffects()) {
            ApplyEffect(entity, effect);
        }

        buffComp->TickTurn();
    }
}

void SystemBuffDebuff::ApplyEffect(Entity* entity, const BuffEffect& effect) {
    if (effect.statAffected == "health") {
        auto* health = entity->GetComponent<ComponentHealth>();
        if (!health) return;

        if (effect.isBuff)
            health->Heal(effect.value);
        else
            health->TakeDamage(effect.value);
    }
    else {
        auto* stats = entity->GetComponent<ComponentStats>();
        if (!stats) return;

        if (!stats->HasStat(effect.statAffected))
            stats->SetStat(effect.statAffected, 0); 

        stats->ModifyStat(effect.statAffected, effect.isBuff ? effect.value : -effect.value);
    }
}
