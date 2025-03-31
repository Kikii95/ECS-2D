#pragma once
#include "System.h"
#include "ComponentNavire.h"
#include "ComponentTransform.h"
#include "ComponentStats.h"

class SystemNavire : public System {
public:
    SystemNavire();

    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    float CalculateSpeedModifier(const ComponentNavire* navire) const;
};
