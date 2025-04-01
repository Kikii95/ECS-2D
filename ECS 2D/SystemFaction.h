#pragma once
#include "System.h"
#include "ComponentFaction.h"
#include "ComponentReputation.h"
#include <string>

enum class FactionRelation {
	Hostile, // Enemi a decider
	Neutral,
	Friendly // Ally a decider
};

class SystemFaction : public System {
public:
    SystemFaction();

	SystemType GetType() const override { return SystemType::Reactive; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

    FactionRelation GetRelationToPlayer(Entity* entity, Entity* player);
	void ApplyZoneModifier(Entity* e);
};

