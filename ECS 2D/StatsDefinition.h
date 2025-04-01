#pragma once
#include <string>
#include <unordered_map>

struct StatsDefinition {
    std::string id;
    std::unordered_map<std::string, int> values;
};
