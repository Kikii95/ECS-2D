#include "ComponentInventory.h"
#include "ItemDatabase.h"
#include "ToolBox.h"

ComponentInventory::ComponentInventory(Entity* entity, float capacity)
    : Component(entity), capacity(capacity) {
}

bool ComponentInventory::AddItem(const ItemInstance& item) {
    const ItemDefinition* def = ItemDatabase::Get().GetItem(item.itemId);
    if (!def) return false;

    float projectedWeight = GetTotalWeight() + def->weight * item.quantity;
    if (projectedWeight > capacity) return false;

    for (auto& i : items) {
        if (i.itemId == item.itemId && def->stackable) {
            i.quantity += item.quantity;
            return true;
        }
    }

    items.push_back(item);
    return true;
}

bool ComponentInventory::RemoveItem(const std::string& itemId, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->itemId == itemId) {
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
        const ItemDefinition* def = ItemDatabase::Get().GetItem(item.itemId);
        if (def) {
            total += def->weight * item.quantity;
        }
    }
    return total;
}

float ComponentInventory::GetCapacity() const {
    return capacity;
}

void ComponentInventory::SetCapacity(float newCapacity) {
    capacity = maximum(0.0f, newCapacity);
}

const std::vector<ItemInstance>& ComponentInventory::GetItems() const {
    return items;
}
