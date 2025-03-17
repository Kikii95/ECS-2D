#include "ComponentWeapon.h"
#include "ComponentTransform.h"
#include "ComponentProjectile.h"
#include "EntityManager.h"
#include <iostream>

ComponentWeapon::ComponentWeapon(Entity* entity, int dmg, float rate, std::string projType)
    : Component(entity), damage(dmg), fireRate(rate), fireCooldown(0.0f), projectileType(projType) {
}

void ComponentWeapon::Update(float dt) {
    if (fireCooldown > 0) {
        fireCooldown -= dt;
    }
}

bool ComponentWeapon::CanFire() const {
    return fireCooldown <= 0;
}

void ComponentWeapon::Fire(const sf::Vector2f& direction) {
    if (!CanFire()) {
        return;
    }

    Entity* projectile = GameEngine::GetInstance().GetEntityManager().CreateEntity();

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (!transform) return;

    sf::Vector2f spawnPosition = transform->GetPosition(); 
    projectile->AddComponent<ComponentTransform>(spawnPosition);

    projectile->AddComponent<ComponentProjectile>(direction, 800.0f, damage, 3.0f);

    std::cout << "[INFO] Projectile tiré ! Type: " << projectileType << ", Damage: " << damage << std::endl;

    fireCooldown = 1.0f / fireRate;
}

void ComponentWeapon::SetDamage(int dmg) {
    damage = dmg;
}

int ComponentWeapon::GetDamage() const {
    return damage;
}

void ComponentWeapon::SetFireRate(float rate) {
    fireRate = rate;
}

float ComponentWeapon::GetFireRate() const {
    return fireRate;
}
