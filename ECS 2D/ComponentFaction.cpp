#include "ComponentFaction.h"
#include "ToolBox.h"

ComponentFaction::ComponentFaction(Entity* entity, const std::string& id)
    : Component(entity), factionId(id), factionName("Unknown"), relationValue(0) {
}

void ComponentFaction::SetFactionId(const std::string& id) {
    factionId = id;
}

std::string ComponentFaction::GetFactionId() const {
    return factionId;
}

void ComponentFaction::SetFactionName(const std::string& name) {
    factionName = name;
}

std::string ComponentFaction::GetFactionName() const {
    return factionName;
}

void ComponentFaction::SetRelationValue(int value) {
    relationValue = clamp(value, -100, 100);
}

int ComponentFaction::GetRelationValue() const {
    return relationValue;
}

FactionRelation ComponentFaction::GetRelationType() const {
    if (relationValue <= -30) return FactionRelation::Hostile;
    if (relationValue >= 30) return FactionRelation::Friendly;
    return FactionRelation::Neutral;
}
