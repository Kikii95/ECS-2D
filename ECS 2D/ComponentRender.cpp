#include "ComponentRender.h"
#include "ComponentTransform.h"

ComponentRender::ComponentRender(Entity* entity)
    : Component(entity), texture(nullptr), color(sf::Color::White), visible(true) {
}

void ComponentRender::SetTexture(sf::Texture* newTexture) {
    texture = newTexture;
    if (texture) {
        sprite.setTexture(*texture);
    }
}

sf::Texture* ComponentRender::GetTexture() const {
    return texture;
}

void ComponentRender::SetColor(const sf::Color& newColor) {
    color = newColor;
    sprite.setColor(color);
}

sf::Color ComponentRender::GetColor() const {
    return color;
}

void ComponentRender::SetVisibility(bool isVisible) {
    visible = isVisible;
}

bool ComponentRender::GetVisibility() const {
    return visible;
}

sf::Sprite& ComponentRender::GetSprite() {
    return sprite;
}

void ComponentRender::UpdateTransform() {
    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (transform) {
        sprite.setPosition(transform->GetPosition());
        sprite.setScale(transform->GetScale());
        sprite.setRotation(transform->GetRotation());
    }
}
