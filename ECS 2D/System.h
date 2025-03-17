#pragma once
#include "Entity.h"

class Entity;

class System {
public:
    virtual ~System() = default;

    virtual void Update(float dt, const std::vector<Entity*>& entities) = 0;
};
