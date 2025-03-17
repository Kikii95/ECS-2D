#pragma once
#include "Component.h"
#include <SFML/System.hpp>

class ComponentProjectile : public Component {
private:
    sf::Vector2f direction;
    float speed;
    float lifetime;
    int damage;

public:
    ComponentProjectile(Entity* entity, const sf::Vector2f& dir, float spd, int dmg, float life = 5.0f);

    void Update(float dt);
    //void OnCollision(Entity* other);

    void SetDirection(const sf::Vector2f& dir);
    sf::Vector2f GetDirection() const;

    void SetSpeed(float spd);
    float GetSpeed() const;

    void SetLifetime(float time);
    float GetLifetime() const;

    void SetDamage(int dmg);
    int GetDamage() const;


    void DestroyProjectile(Entity* target);
};
