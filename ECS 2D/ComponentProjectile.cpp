#include "ComponentProjectile.h"
#include "ComponentTransform.h"
#include "ComponentHealth.h"
#include "EntityManager.h"
#include <iostream>


ComponentProjectile::ComponentProjectile(Entity* entity, const sf::Vector2f& dir, float spd, int dmg, float life)
    : Component(entity), direction(dir), speed(spd), damage(dmg), lifetime(life) {
}

void ComponentProjectile::Update(float dt) {
    lifetime -= dt;
    if (lifetime <= 0) {
        std::cout << "[INFO] Projectile detruit (temps ecoule)." << std::endl;
        GameEngine::GetInstance().GetEntityManager().DestroyEntity(GetEntity()->GetID());
        return;
    }

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (transform) {
        transform->MoveBy(direction * speed * dt);
    }
}

//void ComponentProjectile::OnCollision(Entity* other) {
//    ComponentHealth* health = other->GetComponent<ComponentHealth>();
//    if (health) {
//        health->TakeDamage(damage);
//        std::cout << "[INFO] Projectile a touche une entite et inflige " << damage << " degâts." << std::endl;
//    }
//
//    GameEngine::GetInstance().GetEntityManager().DestroyEntity(GetEntity()->GetID());
//}

void ComponentProjectile::SetDirection(const sf::Vector2f& dir) {
    direction = dir;
}

sf::Vector2f ComponentProjectile::GetDirection() const {
    return direction;
}

void ComponentProjectile::SetSpeed(float spd) {
    speed = spd;
}

float ComponentProjectile::GetSpeed() const {
    return speed;
}

void ComponentProjectile::SetLifetime(float time) {
    lifetime = time;
}

float ComponentProjectile::GetLifetime() const {
    return lifetime;
}

void ComponentProjectile::SetDamage(int dmg) {
    damage = dmg;
}

int ComponentProjectile::GetDamage() const {
    return damage;
}

void ComponentProjectile::DestroyProjectile(Entity* target) {
    ComponentHealth* health = target->GetComponent<ComponentHealth>();
    if (health) {
        health->TakeDamage(damage);
        std::cout << "[INFO] Projectile a touche une entite et inflige " << damage << " degâts." << std::endl;
    }

    GameEngine::GetInstance().GetEntityManager().DestroyEntity(GetEntity()->GetID());
}