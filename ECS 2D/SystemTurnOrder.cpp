#include "SystemTurnOrder.h"
#include <algorithm>

SystemTurnOrder::SystemTurnOrder() {}

void SystemTurnOrder::Update(float dt, const std::vector<Entity*>& entities) {
    
}

void SystemTurnOrder::StartNewRound(const std::vector<Entity*>& entities) {
    turnQueue.clear();
    for (auto* entity : entities) {
        if (entity->HasComponent<ComponentTurnOrder>()) {
            auto* turn = entity->GetComponent<ComponentTurnOrder>();
            turn->SetHasPlayed(false);
            turnQueue.push_back(entity);
        }
    }

    SortByInitiative(turnQueue);
    currentIndex = 0;
}

Entity* SystemTurnOrder::GetNextEntityToPlay(const std::vector<Entity*>& entities) {
    while (currentIndex < static_cast<int>(turnQueue.size())) {
        Entity* e = turnQueue[currentIndex++];
        auto* turn = e->GetComponent<ComponentTurnOrder>();
        if (!turn->HasPlayed()) {
            turn->SetHasPlayed(true);

            auto* state = e->GetComponent<ComponentState>();
            if (state) state->SetState(EntityState::ACTION);

            return e;
        }
    }

    return nullptr; 
}

void SystemTurnOrder::SortByInitiative(std::vector<Entity*>& entities) {
    std::sort(entities.begin(), entities.end(), [](Entity* a, Entity* b) {
        auto* turnA = a->GetComponent<ComponentTurnOrder>();
        auto* turnB = b->GetComponent<ComponentTurnOrder>();
        return turnA->GetTotalInitiative() > turnB->GetTotalInitiative();
        });
}
