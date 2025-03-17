#pragma once
#include <SFML/System.hpp>
#include "Component.h"

enum class ColliderType {
    AABB
};

class ComponentCollider : public Component {
private:
    ColliderType colliderType;
    sf::Vector2f colliderSize;
    bool isTrigger;
    bool isActive = true;

public:
    ComponentCollider(Entity* entity, const sf::Vector2f& size, bool trigger = false);

    void SetColliderSize(const sf::Vector2f& size);
    sf::Vector2f GetColliderSize() const;

    void SetTrigger(bool trigger);
    bool IsTrigger() const;

    void SetActive(bool active);
    bool IsActive() const;

    bool CheckCollision(ComponentCollider* other);
    sf::Vector2f GetOverlap(ComponentCollider* other);
};
