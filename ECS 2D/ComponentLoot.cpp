#include "ComponentLoot.h"

ComponentLoot::ComponentLoot(Entity* entity)
    : Component(entity) {
}

void ComponentLoot::AddItem(const LootItem& item) {
    for (auto& existing : lootItems) {
        if (existing.itemType == item.itemType) {
            existing.quantity += item.quantity;
            return;
        }
    }
    lootItems.push_back(item);
}

void ComponentLoot::RemoveItem(const std::string& type) {
    lootItems.erase(std::remove_if(lootItems.begin(), lootItems.end(),
        [&type](const LootItem& item) {
            return item.itemType == type;
        }), lootItems.end());
}

const std::vector<LootItem>& ComponentLoot::GetLootItems() const {
    return lootItems;
}

void ComponentLoot::SetLootable(bool value) {
    isLootable = value;
}

bool ComponentLoot::IsLootable() const {
    return isLootable;
}
