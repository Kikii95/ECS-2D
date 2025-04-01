#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

enum class ColliderType {
    Solid,
    Mob,
    Object,
    Gatherable
};

class ComponentCollider : public Component {
public:
    ComponentCollider(Entity* entity);

    void SetColliderSize(const sf::Vector2f& size);
    sf::Vector2f GetColliderSize() const;

    void SetType(ColliderType type);
    ColliderType GetColliderType() const;

private:
    sf::Vector2f size;
    ColliderType type = ColliderType::Solid;
};
