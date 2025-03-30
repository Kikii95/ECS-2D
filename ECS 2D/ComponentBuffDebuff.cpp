#include "ComponentBuffDebuff.h"

ComponentBuffDebuff::ComponentBuffDebuff(Entity* entity)
    : Component(entity) {
}

void ComponentBuffDebuff::AddEffect(const BuffEffect& effect) {
    if (!effect.isStackable) {
        for (auto& existing : activeEffects) {
            if (existing.statAffected == effect.statAffected) {
                existing = effect;
                return;
            }
        }
    }
    activeEffects.push_back(effect);
}

void ComponentBuffDebuff::RemoveEffect(const std::string& stat) {
    activeEffects.erase(std::remove_if(activeEffects.begin(), activeEffects.end(),
        [&stat](const BuffEffect& eff) {
            return eff.statAffected == stat;
        }), activeEffects.end());
}

const std::vector<BuffEffect>& ComponentBuffDebuff::GetActiveEffects() const {
    return activeEffects;
}

void ComponentBuffDebuff::TickTurn() {
    for (auto& eff : activeEffects) {
        eff.remainingTurns--;
    }
    ClearExpired();
}

void ComponentBuffDebuff::ClearExpired() {
    activeEffects.erase(std::remove_if(activeEffects.begin(), activeEffects.end(),
        [](const BuffEffect& eff) {
            return eff.remainingTurns <= 0;
        }), activeEffects.end());
}
