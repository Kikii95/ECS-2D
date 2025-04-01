#pragma once
#include "System.h"
#include "ComponentCrewMember.h"
#include "ComponentStats.h"
#include "ComponentHealth.h"
#include "ComponentNavire.h"

class SystemCrewManagement : public System {
public:
    SystemCrewManagement();

	SystemType GetType() const override { return SystemType::TurnBased; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

private:
    void PerformRoleLogic(Entity* crew);
};
