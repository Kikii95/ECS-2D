#include "ComponentDifficulty.h"
#include "ToolBox.h"

ComponentDifficulty::ComponentDifficulty(Entity* entity, float base)
    : Component(entity), baseDifficulty(base), timeModifier(0.0f) {
}

void ComponentDifficulty::SetBaseDifficulty(float value) {
    baseDifficulty = maximum(0.0f, value);
}

float ComponentDifficulty::GetBaseDifficulty() const {
    return baseDifficulty;
}

void ComponentDifficulty::SetTimeModifier(float modifier) {
    timeModifier = modifier;
}

float ComponentDifficulty::GetTimeModifier() const {
    return timeModifier;
}

float ComponentDifficulty::GetEffectiveDifficulty() const {
    return baseDifficulty + timeModifier;
}
