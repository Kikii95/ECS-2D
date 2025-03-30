#pragma once
#include "Component.h"
#include <string>

enum class FactionRelation {
    Hostile,
    Neutral,
    Friendly
};

class ComponentFaction : public Component {
public:
    ComponentFaction(Entity* entity, const std::string& id = "neutral");

    void SetFactionId(const std::string& id);
    std::string GetFactionId() const;

    void SetFactionName(const std::string& name);
    std::string GetFactionName() const;

    void SetRelationValue(int value);
    int GetRelationValue() const;

    FactionRelation GetRelationType() const;

private:
    std::string factionId;
    std::string factionName;
    int relationValue = 0;
};
