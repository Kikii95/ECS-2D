#pragma once
#include "System.h"

class SystemCollision : public System {
public:
    SystemCollision();

    SystemType GetType() const override { return SystemType::Active; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

    // Temporaire : bascule manuelle entre exploration et combat
    void SetExplorationMode(bool active);

private:
    bool explorationMode = true;
    void ResolveCollision(Entity* a, Entity* b);
};
