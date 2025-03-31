#pragma once
#include "Component.h"
#include <string>
#include <unordered_map>

class ComponentStats : public Component {
public:
    ComponentStats(Entity* entity);

    void SetStat(const std::string& name, int value);
    int GetStat(const std::string& name) const;

    void ModifyStat(const std::string& name, int delta);
    bool HasStat(const std::string& name) const;

    const std::unordered_map<std::string, int>& GetAllStats() const;

private:
    std::unordered_map<std::string, int> stats;
};
