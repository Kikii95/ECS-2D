#pragma once
#include "Component.h"
#include <string>
#include <unordered_map>

class ComponentStats : public Component {
public:
    ComponentStats(Entity* entity);

    void LoadFromDefinition(const std::string& definitionId);

    void SetBaseStat(const std::string& name, int value);
    int GetBaseStat(const std::string& name) const;

    void AddModifier(const std::string& name, int bonus);
    void ClearModifiers();

    int GetStat(const std::string& name) const;

    const std::unordered_map<std::string, int>& GetAllBaseStats() const;
    const std::unordered_map<std::string, int>& GetAllModifiers() const;

private:
    std::unordered_map<std::string, int> baseStats;
    std::unordered_map<std::string, int> modifiers;
};
