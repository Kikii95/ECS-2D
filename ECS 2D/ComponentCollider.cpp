#include "ComponentCollider.h"
#include "ComponentTransform.h"

ComponentCollider::ComponentCollider(Entity* entity, const sf::Vector2f& size, bool trigger)
    : Component(entity), colliderType(ColliderType::AABB), colliderSize(size), isTrigger(trigger) {
}

void ComponentCollider::SetColliderSize(const sf::Vector2f& size) {
    colliderSize = size;
}

sf::Vector2f ComponentCollider::GetColliderSize() const {
    return colliderSize;
}

void ComponentCollider::SetTrigger(bool trigger) {
    isTrigger = trigger;
}

bool ComponentCollider::IsTrigger() const {
    return isTrigger;
}

void ComponentCollider::SetActive(bool active) {
    isActive = active;
}

bool ComponentCollider::IsActive() const {
    return isActive;
}

bool ComponentCollider::CheckCollision(ComponentCollider* other) {
    if (!other || !other->isActive) return false;

    ComponentTransform* transformA = GetEntity()->GetComponent<ComponentTransform>();
    ComponentTransform* transformB = other->GetEntity()->GetComponent<ComponentTransform>();

    if (!transformA || !transformB) return false;

    sf::Vector2f posA = transformA->GetPosition();
    sf::Vector2f posB = transformB->GetPosition();

    sf::Vector2f sizeA = colliderSize * 0.5f;
    sf::Vector2f sizeB = other->colliderSize * 0.5f;

    return (std::abs(posA.x - posB.x) < (sizeA.x + sizeB.x)) &&
        (std::abs(posA.y - posB.y) < (sizeA.y + sizeB.y));
}

sf::Vector2f ComponentCollider::GetOverlap(ComponentCollider* other) {
    ComponentTransform* transformA = GetEntity()->GetComponent<ComponentTransform>();
    ComponentTransform* transformB = other->GetEntity()->GetComponent<ComponentTransform>();

    if (!transformA || !transformB) return { 0, 0 };

    sf::Vector2f posA = transformA->GetPosition();
    sf::Vector2f posB = transformB->GetPosition();
    sf::Vector2f sizeA = colliderSize;
    sf::Vector2f sizeB = other->GetColliderSize();

    float overlapX = std::min(posA.x + sizeA.x, posB.x + sizeB.x) - std::max(posA.x, posB.x);
    float overlapY = std::min(posA.y + sizeA.y, posB.y + sizeB.y) - std::max(posA.y, posB.y);

    if (overlapX > 0 && overlapY > 0) {
        return { overlapX, overlapY };
    }
    return { 0, 0 };
}
