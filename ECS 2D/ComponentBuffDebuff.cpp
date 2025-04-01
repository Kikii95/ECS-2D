#include "ComponentBuffDebuff.h"

ComponentBuffDebuff::ComponentBuffDebuff(Entity* entity)
    : Component(entity) {
}

const std::vector<AppliedEffect>& ComponentBuffDebuff::GetActiveEffects() const {
    return activeEffects;
}

void ComponentBuffDebuff::AddEffect(const EffectDefinition* def) {
    if (!def) return;

    for (auto& effect : activeEffects) {
        if (effect.definition && effect.definition->id == def->id) {
            effect.remainingTurns = def->duration;
            return;
        }
    }

    activeEffects.emplace_back(def);
}

void ComponentBuffDebuff::Tick() {
    for (auto it = activeEffects.begin(); it != activeEffects.end(); ) {
        if (--it->remainingTurns <= 0) {
            it = activeEffects.erase(it);
        }
        else {
            ++it;
        }
    }
}
