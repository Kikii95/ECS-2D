#include "ComponentAI.h"
#include "ComponentTransform.h"
#include "ComponentWeapon.h"
#include <iostream>
#include <cmath>

ComponentAI::ComponentAI(Entity* entity, AIState initialState, float detection, float attack, float spd)
    : Component(entity), currentState(initialState), target(nullptr), detectionRange(detection), attackRange(attack), speed(spd) {
}

void ComponentAI::Update(float dt) {
    if (!target) return;

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    ComponentTransform* targetTransform = target->GetComponent<ComponentTransform>();

    if (!transform || !targetTransform) return;

    float distance = std::hypot(targetTransform->GetPosition().x - transform->GetPosition().x,
        targetTransform->GetPosition().y - transform->GetPosition().y);

    if (distance < attackRange) {
        SetState(AIState::ATTACK);
    }
    else if (distance < detectionRange) {
        SetState(AIState::CHASE);
    }
    else {
        SetState(AIState::PATROL);
    }

    switch (currentState) {
    case AIState::PATROL: Patrol(dt); break;
    case AIState::CHASE: Chase(dt); break;
    case AIState::ATTACK: Attack(); break;
    default: break;
    }
}

void ComponentAI::SetState(AIState newState) {
    if (currentState != newState) {
        std::cout << "[INFO] IA changee d'etat: " << static_cast<int>(currentState) << " -> " << static_cast<int>(newState) << std::endl;
        currentState = newState;
    }
}

AIState ComponentAI::GetState() const {
    return currentState;
}

void ComponentAI::SetTarget(Entity* newTarget) {
    target = newTarget;
}

Entity* ComponentAI::GetTarget() const {
    return target;
}

void ComponentAI::Patrol(float dt) {
    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    if (!transform) return;

    sf::Vector2f direction(rand() % 3 - 1, rand() % 3 - 1);
    transform->MoveBy(direction * speed * dt);
}

void ComponentAI::Chase(float dt) {
    if (!target) return;

    ComponentTransform* transform = GetEntity()->GetComponent<ComponentTransform>();
    ComponentTransform* targetTransform = target->GetComponent<ComponentTransform>();
    if (!transform || !targetTransform) return;

    sf::Vector2f direction = targetTransform->GetPosition() - transform->GetPosition();
    float length = std::hypot(direction.x, direction.y);
    if (length > 0) {
        direction /= length;
    }

    transform->MoveBy(direction * speed * dt);
}

void ComponentAI::Attack() {
    ComponentWeapon* weapon = GetEntity()->GetComponent<ComponentWeapon>();
    if (!weapon || !weapon->CanFire() || !target) return;

    sf::Vector2f direction = target->GetComponent<ComponentTransform>()->GetPosition() - GetEntity()->GetComponent<ComponentTransform>()->GetPosition();
    float length = std::hypot(direction.x, direction.y);
    if (length > 0) {
        direction /= length;
    }

    weapon->Fire(direction);
}