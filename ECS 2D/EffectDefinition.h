#pragma once
#include <string>
#include <unordered_map>

enum class EffectType {
    Buff,
    Debuff
};

struct EffectDefinition {
    std::string id;
    std::string name;
    std::string description;
    int duration = 1;
    EffectType type = EffectType::Debuff;
    int tickDamage = 0;
    std::unordered_map<std::string, int> statModifiers;
    std::string icon;
};
