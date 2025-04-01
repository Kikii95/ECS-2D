#pragma once
#include "StatsDefinition.h"
#include <unordered_map>
#include <string>

class StatsDatabase {
public:
    static StatsDatabase& Get();

    void LoadFromFile(const std::string& path);
    const StatsDefinition* GetStats(const std::string& id) const;

private:
    std::unordered_map<std::string, StatsDefinition> profiles;
};
