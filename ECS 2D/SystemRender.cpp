#include "SystemRender.h"
#include "ComponentTransform.h"
#include <iostream>

SystemRender::SystemRender() {}

void SystemRender::Update(float dt, const std::vector<Entity*>& entities) {
    sf::RenderWindow& window = GameEngine::GetInstance().GetWindow();

    for (auto* entity : entities) {
        ComponentRender* render = entity->GetComponent<ComponentRender>();
        if (!render) continue;

        render->UpdateFromTransform();

        if (render->HasTexture()) {
            window.draw(render->GetSprite());
        }
        else {
            window.draw(render->GetShape());
        }
    }
}
