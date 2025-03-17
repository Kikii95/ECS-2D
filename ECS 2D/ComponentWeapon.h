#pragma once
#include "Component.h"
#include <SFML/System.hpp>
#include <string>

class ComponentWeapon : public Component {
private:
    int damage;
    float fireRate;     
    float fireCooldown;  
    std::string projectileType;

public:
    ComponentWeapon(Entity* entity, int dmg, float rate, std::string projType = "bullet");

    void Update(float dt); 
    bool CanFire() const;  
    void Fire(const sf::Vector2f& direction); 

    void SetDamage(int dmg);
    int GetDamage() const;

    void SetFireRate(float rate);
    float GetFireRate() const;
};
