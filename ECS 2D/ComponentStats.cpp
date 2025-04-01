#include "ComponentStats.h"
#include "StatsDatabase.h"

ComponentStats::ComponentStats(Entity* entity)
    : Component(entity) {
}

void ComponentStats::LoadFromDefinition(const std::string& id) {
    const auto* def = StatsDatabase::Get().GetStats(id);
    if (!def) return;

    for (auto it = def->values.begin(); it != def->values.end(); ++it) {
        SetBaseStat(it->first, it->second);
    }
}

void ComponentStats::SetBaseStat(const std::string& name, int value) {
    baseStats[name] = value;
}

int ComponentStats::GetBaseStat(const std::string& name) const {
    auto it = baseStats.find(name);
    return (it != baseStats.end()) ? it->second : 0;
}

void ComponentStats::AddModifier(const std::string& name, int bonus) {
    modifiers[name] += bonus;
}

void ComponentStats::ClearModifiers() {
    modifiers.clear();
}

int ComponentStats::GetStat(const std::string& name) const {
    return GetBaseStat(name) + (modifiers.count(name) ? modifiers.at(name) : 0);
}

const std::unordered_map<std::string, int>& ComponentStats::GetAllBaseStats() const {
    return baseStats;
}

const std::unordered_map<std::string, int>& ComponentStats::GetAllModifiers() const {
    return modifiers;
}
