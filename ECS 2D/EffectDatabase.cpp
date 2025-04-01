#include "EffectDatabase.h"
#include <fstream>

EffectDatabase& EffectDatabase::Get() {
    static EffectDatabase instance;
    return instance;
}

void EffectDatabase::LoadFromFile(const std::string& file) {
    std::ifstream in(file);
    if (!in.is_open()) return;

    nlohmann::json json;
    in >> json;

    for (const auto& e : json["effects"]) {
        EffectDefinition def;
        def.id = e.value("id", "");
        def.name = e.value("name", "");
        def.description = e.value("description", "");
        def.duration = e.value("duration", 1);
        def.type = e.value("type", "debuff") == "buff" ? EffectType::Buff : EffectType::Debuff;
        def.tickDamage = e.value("tickDamage", 0);
        def.icon = e.value("icon", "");

        if (e.contains("statModifiers") && e["statModifiers"].is_object()) {
            for (auto it = e["statModifiers"].begin(); it != e["statModifiers"].end(); ++it) {
                def.statModifiers[it.key()] = it.value().get<int>();
            }
        }

        effects[def.id] = def;
    }
}

const EffectDefinition* EffectDatabase::GetEffect(const std::string& id) const {
    auto it = effects.find(id);
    return it != effects.end() ? &it->second : nullptr;
}
