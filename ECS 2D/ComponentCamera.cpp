#include "ComponentCamera.h"
#include "ComponentTransform.h"

ComponentCamera::ComponentCamera(Entity* entity)
    : Component(entity) {
    view.setSize(1280, 720); 
    view.setCenter(0, 0);  
}

void ComponentCamera::SetPosition(const sf::Vector2f& position) {
    view.setCenter(position);
}

sf::Vector2f ComponentCamera::GetPosition() const {
    return view.getCenter();
}

void ComponentCamera::SetZoom(float factor) {
    view.zoom(factor);
}

float ComponentCamera::GetZoom() const {
    return view.getSize().x / 1280.0f;
}

sf::View& ComponentCamera::GetView() {
    return view;
}
