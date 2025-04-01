#pragma once
#include "Component.h"
#include <string>

class ComponentWeapon : public Component {
public:
    ComponentWeapon(Entity* entity, const std::string& weaponId);

    const std::string& GetWeaponId() const;
    void SetWeaponId(const std::string& id);

    int GetDamage() const;
    int GetRange() const;
    bool IsValid() const;

private:
    std::string weaponId;
};
