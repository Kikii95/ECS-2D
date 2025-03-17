#include "ComponentTransform.h"

ComponentTransform::ComponentTransform(Entity* entity, sf::Vector2f startPos)
    : Component(entity), position(startPos) {
}

void ComponentTransform::SetPosition(const sf::Vector2f& pos) {
    position = pos;
}

sf::Vector2f ComponentTransform::GetPosition() const {
    return position;
}

void ComponentTransform::SetScale(const sf::Vector2f& sca) {
    scale = sca;
}

sf::Vector2f ComponentTransform::GetScale() const {
    return scale;
}

void ComponentTransform::SetRotation(float angle) {
    rotation = angle;
}

float ComponentTransform::GetRotation() const {
    return rotation;
}

void ComponentTransform::MoveBy(const sf::Vector2f& delta) {
    position += delta;
}

void ComponentTransform::Rotate(float angle) {
    rotation += angle;
}
