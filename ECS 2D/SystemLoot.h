#pragma once
#include "System.h"
#include "ItemInstance.h"
#include <string>

class SystemLoot : public System {
public:
    SystemLoot();

    SystemType GetType() const override { return SystemType::Reactive; }

    void GenerateLoot(Entity* source, Entity* receiver);

    void Update(float dt, const std::vector<Entity*>&) override {}
};
