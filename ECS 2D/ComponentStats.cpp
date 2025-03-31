#include "ComponentStats.h"

ComponentStats::ComponentStats(Entity* entity)
    : Component(entity) {
}

void ComponentStats::SetStat(const std::string& name, int value) {
    stats[name] = value;
}

int ComponentStats::GetStat(const std::string& name) const {
    auto it = stats.find(name);
    if (it != stats.end()) {
        return it->second;
    }
    return 0;
}

void ComponentStats::ModifyStat(const std::string& name, int delta) {
    stats[name] = GetStat(name) + delta;
}

bool ComponentStats::HasStat(const std::string& name) const {
    return stats.find(name) != stats.end();
}

const std::unordered_map<std::string, int>& ComponentStats::GetAllStats() const {
    return stats;
}
