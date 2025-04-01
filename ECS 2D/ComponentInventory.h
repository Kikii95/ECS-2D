#pragma once
#include "Component.h"
#include "ItemInstance.h"
#include <vector>
#include <string>

class ComponentInventory : public Component {
public:
    ComponentInventory(Entity* entity, float capacity = 100.0f);

    bool AddItem(const ItemInstance& item);
    bool RemoveItem(const std::string& itemId, int quantity);

    float GetTotalWeight() const;
    float GetCapacity() const;
    void SetCapacity(float newCapacity);

    const std::vector<ItemInstance>& GetItems() const;

private:
    std::vector<ItemInstance> items;
    float capacity;
};
