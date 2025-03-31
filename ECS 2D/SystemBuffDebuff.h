#pragma once
#include "System.h"
#include "ComponentBuffDebuff.h"
#include "ComponentStats.h"
#include "ComponentHealth.h"

class SystemBuffDebuff : public System {
public:
    SystemBuffDebuff();

    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void ApplyEffect(Entity* entity, const BuffEffect& effect);
};
