#include "ComponentWeapon.h"
#include "ItemDatabase.h"

ComponentWeapon::ComponentWeapon(Entity* entity, const std::string& id)
    : Component(entity), weaponId(id) {}

const std::string& ComponentWeapon::GetWeaponId() const {
    return weaponId;
}

void ComponentWeapon::SetWeaponId(const std::string& id) {
    weaponId = id;
}

int ComponentWeapon::GetDamage() const {
    const auto* def = ItemDatabase::Get().GetItem(weaponId);
    return def ? def->damage : 0;
}

int ComponentWeapon::GetRange() const {
    const auto* def = ItemDatabase::Get().GetItem(weaponId);
    return def ? def->range : 0;
}

bool ComponentWeapon::IsValid() const {
    return ItemDatabase::Get().GetItem(weaponId) != nullptr;
}
