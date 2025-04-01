#pragma once
#include "System.h"
#include "ActionDefinition.h"

class SystemAction : public System {
public:
    SystemAction();

    SystemType GetType() const override { return SystemType::Reactive; }

    void Update(float dt, const std::vector<Entity*>& entities) override {}

    void ExecuteAction(Entity* entity, const ActionData& action);
};
