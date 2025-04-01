#include "SystemDifficulty.h"
#include "ComponentDifficulty.h"
#include "ComponentStats.h"

SystemDifficulty::SystemDifficulty() {}

void SystemDifficulty::Update(float dt, const std::vector<Entity*>& entities) {
    float totalTime = GameEngine::GetInstance().GetTimer().TotalTime();

    float mod = ComputeTimeModifier(totalTime);

    for (Entity* e : entities) {
        ApplyToEntity(e, mod);
    }
}


float SystemDifficulty::ComputeTimeModifier(float timeSeconds) const {
    return 0.1f * std::log(1.f + timeSeconds / 120.f);
}


void SystemDifficulty::ApplyToEntity(Entity* entity, float modifier) {
    auto* difficulty = entity->GetComponent<ComponentDifficulty>();
    auto* stats = entity->GetComponent<ComponentStats>();

    if (!difficulty || !stats) return;

    difficulty->SetTimeModifier(modifier);

    stats->ClearModifiers();

    float total = difficulty->GetEffectiveDifficulty();

    if (total > 1.0f) {
        int bonus = static_cast<int>((total - 1.0f) * 4);
        stats->AddModifier("attack", bonus);
        stats->AddModifier("defense", bonus / 2);
    }
}
