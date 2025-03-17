#include "SystemRender.h"
#include "ComponentTransform.h"
#include <iostream>

SystemRender::SystemRender() {}

void SystemRender::Update(float dt, const std::vector<Entity*>& entities) {
    sf::RenderWindow& window = GameEngine::GetInstance().GetWindow(); 

    window.clear(sf::Color::Black);

    for (auto* entity : entities) {
        ComponentRender* render = entity->GetComponent<ComponentRender>();
        if (!render || !render->GetVisibility()) continue;

        ComponentTransform* transform = entity->GetComponent<ComponentTransform>();
        if (!transform) continue;

        render->UpdateTransform();

        window.draw(render->GetSprite());
    }

    window.display();
}
