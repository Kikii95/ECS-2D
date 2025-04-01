#include "SystemCamera.h"
#include "ComponentCamera.h"
#include "ComponentTransform.h"
#include "GameEngine.h"
#include <SFML/Graphics/View.hpp>

SystemCamera::SystemCamera() {}

void SystemCamera::Update(float dt, const std::vector<Entity*>& entities) {
    for (Entity* entity : entities) {
        auto* camera = entity->GetComponent<ComponentCamera>();
        auto* transform = entity->GetComponent<ComponentTransform>();

        if (camera && transform) {
            sf::View view;
            view.setSize(1280.f, 720.f); // TO DO : get window size
            view.setCenter(transform->GetPosition());

            GameEngine::GetInstance().GetWindow().setView(view);
            break; 
        }
    }
}
