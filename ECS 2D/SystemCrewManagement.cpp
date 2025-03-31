#include "SystemCrewManagement.h"
#include <iostream>

SystemCrewManagement::SystemCrewManagement() {}

void SystemCrewManagement::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        if (!entity->HasComponent<ComponentCrewMember>()) continue;
        PerformRoleLogic(entity);
    }
}

void SystemCrewManagement::PerformRoleLogic(Entity* crew) {
    auto* member = crew->GetComponent<ComponentCrewMember>();
    auto role = member->GetRole();

    switch (role) {
    case CrewRole::Medic: {
        auto* health = crew->GetComponent<ComponentHealth>();
        if (health && health->GetHealth() < health->GetMaxHealth()) {
            health->Heal(1); 
            std::cout << "[SystemCrewManagement] Soins prodigués." << std::endl;
        }
        break;
    }

    case CrewRole::Sailor: {
        //TO DO
        break;
    }

    default:
        break;
    }
}
