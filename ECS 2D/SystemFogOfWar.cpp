#include "SystemFogOfWar.h"
#include <cmath>

SystemFogOfWar::SystemFogOfWar() {}

void SystemFogOfWar::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* fog = entity->GetComponent<ComponentFogOfWar>();
        auto* transform = entity->GetComponent<ComponentTransform>();
        if (!fog || !transform) continue;

        RevealAround(entity, 5); 
    }
}

void SystemFogOfWar::RevealAround(Entity* entity, int radius) {
    auto* fog = entity->GetComponent<ComponentFogOfWar>();
    auto* transform = entity->GetComponent<ComponentTransform>();
    if (!fog || !transform) return;

    sf::Vector2f pos = transform->GetPosition();
    int x = static_cast<int>(pos.x) / 32; 
    int y = static_cast<int>(pos.y) / 32;

    for (int dx = -radius; dx <= radius; ++dx) {
        for (int dy = -radius; dy <= radius; ++dy) {
            if (std::sqrt(dx * dx + dy * dy) <= radius) {
                fog->Reveal({ x + dx, y + dy });
            }
        }
    }
}
