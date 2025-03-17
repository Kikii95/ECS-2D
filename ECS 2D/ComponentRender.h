#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class ComponentRender : public Component {
private:
    sf::Sprite sprite;
    sf::Texture* texture;
    sf::Color color;
    bool visible;

public:
    ComponentRender(Entity* entity);

    void SetTexture(sf::Texture* newTexture);
    sf::Texture* GetTexture() const;

    void SetColor(const sf::Color& newColor);
    sf::Color GetColor() const;

    void SetVisibility(bool isVisible);
    bool GetVisibility() const;

    sf::Sprite& GetSprite();

    void UpdateTransform();
};
