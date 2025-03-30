#include "ComponentInventory.h"
#include "ToolBox.h"

ComponentInventory::ComponentInventory(Entity* entity, float capacity)
    : Component(entity), capacity(capacity) {
}

bool ComponentInventory::AddItem(const InventoryItem& item) {
    float projectedWeight = GetTotalWeight() + item.GetTotalWeight();
    if (projectedWeight > capacity) return false;

    for (auto& i : items) {
        if (i.itemType == item.itemType && i.unitWeight == item.unitWeight) {
            i.quantity += item.quantity;
            return true;
        }
    }

    items.push_back(item);
    return true;
}

bool ComponentInventory::RemoveItem(const std::string& type, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->itemType == type) {
            if (it->quantity <= quantity) {
                items.erase(it);
            }
            else {
                it->quantity -= quantity;
            }
            return true;
        }
    }
    return false;
}

float ComponentInventory::GetTotalWeight() const {
    float total = 0.0f;
    for (const auto& item : items) {
        total += item.GetTotalWeight();
    }
    return total;
}

float ComponentInventory::GetCapacity() const {
    return capacity;
}

void ComponentInventory::SetCapacity(float newCapacity) {
    capacity = maximum(0.0f, newCapacity);
}

const std::vector<InventoryItem>& ComponentInventory::GetItems() const {
    return items;
}
