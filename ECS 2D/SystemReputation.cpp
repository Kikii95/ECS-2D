#include "SystemReputation.h"
#include <iostream>

SystemReputation::SystemReputation() {}

void SystemReputation::Update(float dt, const std::vector<Entity*>& entities) {
}

void SystemReputation::ModifyReputation(Entity* entity, const std::string& factionId, int delta) {
    auto* rep = entity->GetComponent<ComponentReputation>();
    if (!rep) return;

    rep->ModifyReputation(factionId, delta);
    std::cout << "[SystemReputation] Réputation modifiée pour " << factionId
        << " -> nouvelle valeur : " << rep->GetReputation(factionId) << std::endl;
}

int SystemReputation::GetReputationValue(Entity* entity, const std::string& factionId) {
    auto* rep = entity->GetComponent<ComponentReputation>();
    return rep ? rep->GetReputation(factionId) : 0;
}

ReputationLevel SystemReputation::GetReputationLevel(Entity* entity, const std::string& factionId) {
    auto* rep = entity->GetComponent<ComponentReputation>();
    return rep ? rep->GetReputationLevel(factionId) : ReputationLevel::Neutral;
}
