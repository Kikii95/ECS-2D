#pragma once
#include "Component.h"
#include <string>
#include <unordered_map>

enum class EntityState {
    IDLE,
    RUNNING,
    JUMPING,
    ATTACKING,
    DAMAGED,
    DEAD,
    WAITING,
	ACTION
};

class ComponentState : public Component {
private:
    EntityState currentState;
    std::unordered_map<EntityState, std::string> stateNames;

public:
    ComponentState(Entity* entity, EntityState initialState = EntityState::IDLE);

    void SetState(EntityState newState);
    EntityState GetState() const;
    std::string GetStateName() const;


};
