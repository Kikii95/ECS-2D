#include "ComponentLoot.h"

ComponentLoot::ComponentLoot(Entity* entity)
    : Component(entity) {
}

void ComponentLoot::AddLoot(const LootSlot& loot) {
    lootTable.push_back(loot);
}

const std::vector<LootSlot>& ComponentLoot::GetLootTable() const {
    return lootTable;
}
