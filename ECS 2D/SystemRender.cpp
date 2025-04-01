#include "SystemRender.h"
#include "ComponentTransform.h"
#include "ComponentRender.h"
#include "ComponentCollider.h"
#include <iostream>

SystemRender::SystemRender() {}

void SystemRender::Update(float dt, const std::vector<Entity*>& entities) {
    sf::RenderWindow& window = GameEngine::GetInstance().GetWindow();

    for (auto* entity : entities) {
        ComponentRender* render = entity->GetComponent<ComponentRender>();
        if (!render) continue;

        ComponentTransform* transform = entity->GetComponent<ComponentTransform>();
        ComponentCollider* collider = entity->GetComponent<ComponentCollider>();

        if (!transform) continue;

        sf::Vector2f position = transform->GetPosition();

        if (render->HasTexture()) {
            render->GetSprite().setPosition(position);
        }
        else {
            sf::Vector2f size = collider ? collider->GetColliderSize() : sf::Vector2f(50, 50);
            render->GetShape().setSize(size);
            render->GetShape().setPosition(position);
        }


        if (render->HasTexture()) {
            window.draw(render->GetSprite());
        }
        else {
            window.draw(render->GetShape());
        }
    }
};