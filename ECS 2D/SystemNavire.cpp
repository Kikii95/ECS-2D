#include "SystemNavire.h"
#include "ToolBox.h"

SystemNavire::SystemNavire() {}

void SystemNavire::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* navire = entity->GetComponent<ComponentNavire>();
        auto* transform = entity->GetComponent<ComponentTransform>();
        if (!navire || !transform) continue;

        float speedModifier = CalculateSpeedModifier(navire);
        sf::Vector2f direction = { 1.0f, 0.0f }; 

        transform->MoveBy(direction * speedModifier * dt);

    }
}

float SystemNavire::CalculateSpeedModifier(const ComponentNavire* navire) const {
    float sailIntegrity = navire->GetIntegrity(ShipPart::Sail);
    float rudderIntegrity = navire->GetIntegrity(ShipPart::Rudder);

    float avg = (sailIntegrity + rudderIntegrity) / 2.0f;
    return clamp(avg / 100.0f, 0.1f, 1.0f);
}
