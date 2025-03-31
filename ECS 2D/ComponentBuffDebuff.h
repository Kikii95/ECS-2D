#pragma once
#include "Component.h"
#include <string>
#include <vector>

struct BuffEffect {
    std::string statAffected;
    int value;
    int remainingTurns;
    bool isBuff; // true = buff, false = debuff
    bool isStackable;

    BuffEffect(const std::string& stat, int val, int turns, bool buff, bool stackable)
        : statAffected(stat), value(val), remainingTurns(turns), isBuff(buff), isStackable(stackable) {
    }
};

class ComponentBuffDebuff : public Component {
public:
    ComponentBuffDebuff(Entity* entity);

    void AddEffect(const BuffEffect& effect);
    void RemoveEffect(const std::string& stat);

    const std::vector<BuffEffect>& GetActiveEffects() const;

    void TickTurn(); 
    void ClearExpired();

private:
    std::vector<BuffEffect> activeEffects;
};
