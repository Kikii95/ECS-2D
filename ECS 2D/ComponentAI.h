#pragma once
#include "Component.h"
#include "ComponentState.h"
#include <SFML/System.hpp>

enum class AIState {
    IDLE,
    PATROL,
    CHASE,
    ATTACK,
    FLEE
};

class ComponentAI : public Component {
private:
    AIState currentState;
    Entity* target;
    float detectionRange;
    float attackRange;
    float speed;

public:
    ComponentAI(Entity* entity, AIState initialState = AIState::IDLE, float detection = 300.0f, float attack = 50.0f, float spd = 100.0f);

    void Update(float dt); 
    void SetState(AIState newState);
    AIState GetState() const;

    void SetTarget(Entity* newTarget);
    Entity* GetTarget() const;

    void Patrol(float dt);  
    void Chase(float dt);
    void Attack();      
};
