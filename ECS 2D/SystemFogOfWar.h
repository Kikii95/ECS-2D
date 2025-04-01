#pragma once
#include "System.h"
#include "ComponentFogOfWar.h"
#include "ComponentTransform.h"

class SystemFogOfWar : public System {
public:
    SystemFogOfWar();

	SystemType GetType() const override { return SystemType::UI; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

    void RevealAround(Entity* entity, int radius);
};
