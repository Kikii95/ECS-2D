#pragma once
#include "EffectDefinition.h"
#include <unordered_map>
#include "json.hpp"

class EffectDatabase {
public:
    static EffectDatabase& Get();

    void LoadFromFile(const std::string& file);
    const EffectDefinition* GetEffect(const std::string& id) const;

private:
    std::unordered_map<std::string, EffectDefinition> effects;
};
