#pragma once
#include "System.h"
#include "ComponentInventory.h"
#include "ItemInstance.h"
#include <string>

class SystemInventory : public System {
public:
    SystemInventory();

	SystemType GetType() const override { return SystemType::Reactive; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

    bool TransferItem(Entity* from, Entity* to, const std::string& itemId, int quantity);
};
