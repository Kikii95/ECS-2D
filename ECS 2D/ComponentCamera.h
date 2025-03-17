#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class ComponentCamera : public Component {
private:
    sf::View view;

public:
    ComponentCamera(Entity* entity);

    void SetPosition(const sf::Vector2f& position);
    sf::Vector2f GetPosition() const;

    void SetZoom(float factor);
    float GetZoom() const;

    void SyncWithTransform();
    sf::View& GetView();
};
