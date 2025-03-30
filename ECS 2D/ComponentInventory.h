#pragma once
#include "Component.h"
#include <string>
#include <vector>

struct InventoryItem {
    std::string itemType;
    int quantity;
    float unitWeight;

    InventoryItem(const std::string& type, int qty, float weight)
        : itemType(type), quantity(qty), unitWeight(weight) {
    }

    float GetTotalWeight() const {
        return unitWeight * quantity;
    }
};

class ComponentInventory : public Component {
public:
    ComponentInventory(Entity* entity, float capacity = 100.0f);

    bool AddItem(const InventoryItem& item);
    bool RemoveItem(const std::string& type, int quantity);

    float GetTotalWeight() const;
    float GetCapacity() const;
    void SetCapacity(float newCapacity);

    const std::vector<InventoryItem>& GetItems() const;

private:
    std::vector<InventoryItem> items;
    float capacity;
};
