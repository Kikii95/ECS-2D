#pragma once
#include "Component.h"
#include "ItemInstance.h"
#include <vector>

struct LootSlot {
    ItemInstance item;
	float dropChance = 1.0f; // = 100% 

    LootSlot(const ItemInstance& instance, float chance = 1.0f)
        : item(instance), dropChance(chance) {
    }
};

class ComponentLoot : public Component {
public:
    ComponentLoot(Entity* entity);

    void AddLoot(const LootSlot& loot);
    const std::vector<LootSlot>& GetLootTable() const;

private:
    std::vector<LootSlot> lootTable;
};
