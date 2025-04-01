#pragma once
#include "System.h"
#include "ComponentMerchant.h"
#include "ComponentInventory.h"
#include <string>

class SystemMerchant : public System {
public:
    SystemMerchant();

	SystemType GetType() const override { return SystemType::Reactive; }
    void Update(float dt, const std::vector<Entity*>& entities) override;

    bool BuyItem(Entity* buyer, Entity* merchant, const std::string& itemId, int quantity);
    bool SellItem(Entity* seller, Entity* merchant, const std::string& itemId, int quantity);

private:
    int GetItemPrice(const MerchantSlot& slot, float rate) const;
};
