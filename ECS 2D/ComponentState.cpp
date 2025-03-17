#include "ComponentState.h"
#include <iostream>

ComponentState::ComponentState(Entity* entity, EntityState initialState)
    : Component(entity), currentState(initialState) {
    stateNames[EntityState::IDLE] = "IDLE";
    stateNames[EntityState::RUNNING] = "RUNNING";
    stateNames[EntityState::JUMPING] = "JUMPING";
    stateNames[EntityState::ATTACKING] = "ATTACKING";
    stateNames[EntityState::DAMAGED] = "DAMAGED";
    stateNames[EntityState::DEAD] = "DEAD";
}

void ComponentState::SetState(EntityState newState) {
    if (currentState != newState) {
        std::cout << "[INFO] Changement d'état: " << stateNames[currentState] << " -> " << stateNames[newState] << std::endl;
        currentState = newState;
    }
}

EntityState ComponentState::GetState() const {
    return currentState;
}

std::string ComponentState::GetStateName() const {
    return stateNames.at(currentState);
}
