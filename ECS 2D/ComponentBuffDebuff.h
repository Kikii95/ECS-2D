#pragma once
#include "Component.h"
#include <vector>
#include "EffectDefinition.h"

struct AppliedEffect {
    const EffectDefinition* definition = nullptr;
    int remainingTurns = 0;

    AppliedEffect(const EffectDefinition* def)
        : definition(def), remainingTurns(def ? def->duration : 0) {
    }
};


class ComponentBuffDebuff : public Component {
public:
    ComponentBuffDebuff(Entity* entity);

    const std::vector<AppliedEffect>& GetActiveEffects() const;
    void AddEffect(const EffectDefinition* def);
    void Tick();

private:
    std::vector<AppliedEffect> activeEffects;
};
