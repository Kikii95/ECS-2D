#include "ComponentCollider.h"

ComponentCollider::ComponentCollider(Entity* entity)
    : Component(entity) {
}

void ComponentCollider::SetColliderSize(const sf::Vector2f& s) {
    size = s;
}

sf::Vector2f ComponentCollider::GetColliderSize() const {
    return size;
}

void ComponentCollider::SetType(ColliderType t) {
    type = t;
}

ColliderType ComponentCollider::GetColliderType() const {
    return type;
}
