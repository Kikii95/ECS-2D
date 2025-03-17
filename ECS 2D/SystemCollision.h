#pragma once
#include "System.h"
#include "ComponentCollider.h"
#include "ComponentTransform.h"
#include <vector>

class SystemCollision : public System {
public:
    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void HandleProjectileCollision(Entity* projectile, Entity* target);
    void HandleWallCollision(Entity* entityA, Entity* entityB);
    void HandleEntityCollision(Entity* entityA, Entity* entityB);
    void ResolveCollision(Entity* entityA, Entity* entityB, const sf::Vector2f& overlap);
};
