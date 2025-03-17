#include "ComponentHealth.h"
#include "ComponentRender.h"
#include "ComponentCollider.h"
#include "EntityManager.h"
#include <iostream>

ComponentHealth::ComponentHealth(Entity* entity, int hp, int dmg)
    : Component(entity), health(hp), maxHealth(hp), damage(dmg) {
}

void ComponentHealth::Logs() {
    HEAD("sys_HEALTH") << "Entité " << GetEntity()->GetID() << " : "
        << health << " / " << maxHealth << " HP" << ENDL;
}

void ComponentHealth::SetHealth(int hp) {
    health = std::max(0, std::min(hp, maxHealth)); 
}

int ComponentHealth::GetHealth() const {
    return health;
}

void ComponentHealth::SetMaxHealth(int hp) {
    maxHealth = hp;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

int ComponentHealth::GetMaxHealth() const {
    return maxHealth;
}

void ComponentHealth::SetDamage(int dmg) {
    damage = dmg;
}

int ComponentHealth::GetDamage() const {
    return damage;
}

void ComponentHealth::TakeDamage(int amount) {
    health -= amount;
    if (health <= 0) {
        OnDeath();
    }
}

void ComponentHealth::Heal(int amount) {
    if (health > 0) {
        health = std::min(health + amount, maxHealth);
    }
}

bool ComponentHealth::IsDead() const {
    return health <= 0;
}

void ComponentHealth::OnDeath() {
    ComponentRender* render = GetEntity()->GetComponent<ComponentRender>();
    if (render) render->SetVisibility(false);

    ComponentCollider* collider = GetEntity()->GetComponent<ComponentCollider>();
    if (collider) collider->SetActive(false);

    // TODO : Ajouter animation mort, drop, etc.

    std::cout << "[INFO] Entité " << GetEntity()->GetID() << " est morte." << std::endl;
    GameEngine::GetInstance().GetEntityManager().DestroyEntity(GetEntity()->GetID());
}