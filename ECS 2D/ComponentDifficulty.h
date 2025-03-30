#pragma once
#include "Component.h"

class ComponentDifficulty : public Component {
public:
    ComponentDifficulty(Entity* entity, float base = 1.0f);

    void SetBaseDifficulty(float value);
    float GetBaseDifficulty() const;

    void SetTimeModifier(float modifier);
    float GetTimeModifier() const;

    float GetEffectiveDifficulty() const;

private:
    float baseDifficulty;
    float timeModifier;
};
