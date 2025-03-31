#pragma once
#include "System.h"
#include "ComponentAction.h"
#include "ComponentState.h"
#include "ComponentStats.h"
#include "ComponentHealth.h"
#include "ComponentBuffDebuff.h"

class SystemAction : public System {
public:
    SystemAction();

    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void ExecuteAction(Entity* entity, const ActionData& action);
};
