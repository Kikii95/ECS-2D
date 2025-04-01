#include "SystemWeapon.h"
#include "ComponentWeapon.h"
#include "ComponentStats.h"
#include "ItemDatabase.h"
#include <iostream>

SystemWeapon::SystemWeapon() {}

int SystemWeapon::CalculateDamage(Entity* attacker, Entity* target) {
    auto* weapon = attacker->GetComponent<ComponentWeapon>();
    auto* stats = attacker->GetComponent<ComponentStats>();

    int baseDamage = 0;

    if (weapon) {
        const ItemDefinition* def = ItemDatabase::Get().GetItem(weapon->GetWeaponId());
        if (def) baseDamage += def->damage;
    }

    if (stats) baseDamage += stats->GetStat("attack");

    std::cout << "[SystemWeapon] Dégâts calculés : " << baseDamage << std::endl;
    return baseDamage;
}
