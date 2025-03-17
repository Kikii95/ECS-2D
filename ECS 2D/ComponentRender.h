#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class ComponentRender : public Component {
private:
    sf::RectangleShape shape;

    sf::Sprite sprite;
    sf::Texture* texture;
    sf::Color color;
    bool visible;
    bool useTexture = false;

public:
    ComponentRender(Entity* entity);

    void SetTexture(sf::Texture* newTexture);
    sf::Texture* GetTexture() const;
    bool HasTexture() const;

    void SetColor(const sf::Color& newColor);
    sf::Color GetColor() const;

    void SetVisibility(bool isVisible);
    bool GetVisibility() const;

    sf::Sprite& GetSprite();
    sf::RectangleShape& GetShape();

    void UpdateFromTransform();
};
