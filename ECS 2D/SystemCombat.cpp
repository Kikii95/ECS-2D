#include "SystemCombat.h"
#include "ItemDatabase.h"
#include "SystemBuffDebuff.h"
#include <iostream>

SystemCombat::SystemCombat() {}

void SystemCombat::Update(float dt, const std::vector<Entity*>& entities) {
    for (Entity* entity : entities) {
        auto* state = entity->GetComponent<ComponentState>();
        auto* ai = entity->GetComponent<ComponentAI>();
        if (!state || state->GetState() != EntityState::ATTACKING || !ai) continue;

        Entity* target = ai->GetTarget();
        if (target) {
            ExecuteAttack(entity, target);
            state->SetState(EntityState::WAITING);
        }
    }
}

void SystemCombat::ExecuteAttack(Entity* attacker, Entity* target) {
    if (!attacker || !target) return;

    int damage = CalculateDamage(attacker, target);
    auto* health = target->GetComponent<ComponentHealth>();
    if (health) {
        health->TakeDamage(damage);
        std::cout << "[Combat] Dégâts infligés : " << damage << std::endl;
    }

    auto* weapon = attacker->GetComponent<ComponentWeapon>();
    if (weapon) {
        const ItemDefinition* itemDef = ItemDatabase::Get().GetItem(weapon->GetWeaponId());
        if (itemDef && !itemDef->effectId.empty()) {
            ApplyWeaponEffect(attacker, target, itemDef->effectId);
        }
    }
}

int SystemCombat::CalculateDamage(Entity* attacker, Entity* target) {
    int atk = 0;
    int def = 0;

    if (auto* stats = attacker->GetComponent<ComponentStats>())
        atk += stats->GetStat("attack");

    if (auto* weapon = attacker->GetComponent<ComponentWeapon>()) {
        const auto* def = ItemDatabase::Get().GetItem(weapon->GetWeaponId());
        if (def) atk += def->damage;
    }

    if (auto* stats = target->GetComponent<ComponentStats>())
        def += stats->GetStat("defense");

    int raw = atk - def;
    return std::max(1, raw);
}

void SystemCombat::ApplyWeaponEffect(Entity* attacker, Entity* target, const std::string& effectId) {
    if (effectId.empty() || !target) return;


    GameEngine::GetInstance().GetSystemManager().GetSystem<SystemBuffDebuff>()->ApplyEffect(target, effectId);
    std::cout << "[Combat] Effet de l’arme appliqué : " << effectId << std::endl;
}
