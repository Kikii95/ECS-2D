#include "SystemHealth.h"
#include <iostream>

SystemHealth::SystemHealth() {}

void SystemHealth::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* health = entity->GetComponent<ComponentHealth>();
        if (!health) continue;

        if (health->IsDead()) {
            health->OnDeath();

            // Si un ComponentState est présent, on change l'état
            if (auto* state = entity->GetComponent<ComponentState>()) {
                state->SetState(EntityState::DEAD);
            }

            std::cout << "[SystemHealth] Entité morte." << std::endl;
        }
    }
}
