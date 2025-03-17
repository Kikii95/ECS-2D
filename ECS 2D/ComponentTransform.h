#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class ComponentTransform : public Component {
private:
    sf::Vector2f position;
    sf::Vector2f scale;
    float rotation; 

public:
    ComponentTransform(Entity* entity, sf::Vector2f startPos);

    void SetPosition(const sf::Vector2f& pos);
    sf::Vector2f GetPosition() const;

    void SetScale(const sf::Vector2f& sca);
    sf::Vector2f GetScale() const;

    void SetRotation(float angle);
    float GetRotation() const;

    void MoveBy(const sf::Vector2f& delta);
    void Rotate(float angle);
};
