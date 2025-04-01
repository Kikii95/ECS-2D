#pragma once
#include "System.h"

class SystemDifficulty : public System {
public:
    SystemDifficulty();

    SystemType GetType() const override { return SystemType::Active; }

    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    float ComputeTimeModifier(float timeSeconds) const;
    void ApplyToEntity(Entity* entity, float modifier);
};
