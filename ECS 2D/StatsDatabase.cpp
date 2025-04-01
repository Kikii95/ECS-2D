#include "StatsDatabase.h"
#include "json.hpp"
#include <fstream>

StatsDatabase& StatsDatabase::Get() {
    static StatsDatabase instance;
    return instance;
}

void StatsDatabase::LoadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) return;

    nlohmann::json json;
    in >> json;

    for (const auto& entry : json["stats"]) {
        StatsDefinition def;
        def.id = entry.value("id", "");

        for (auto it = entry.begin(); it != entry.end(); ++it) {
            if (it.key() != "id") {
                def.values[it.key()] = it.value().get<int>();
            }
        }

        profiles[def.id] = def;
    }
}

const StatsDefinition* StatsDatabase::GetStats(const std::string& id) const {
    auto it = profiles.find(id);
    return it != profiles.end() ? &it->second : nullptr;
}
