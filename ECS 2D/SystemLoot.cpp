#include "SystemLoot.h"
#include "ComponentLoot.h"
#include "ComponentInventory.h"
#include "ItemDatabase.h"
#include <cstdlib>
#include <iostream>

SystemLoot::SystemLoot() {}

void SystemLoot::GenerateLoot(Entity* source, Entity* receiver) {
    auto* loot = source->GetComponent<ComponentLoot>();
    auto* inventory = receiver->GetComponent<ComponentInventory>();
    if (!loot || !inventory) return;

    for (const LootSlot& slot : loot->GetLootTable()) {
        float roll = static_cast<float>(rand()) / RAND_MAX;
        if (roll <= slot.dropChance) {
            if (inventory->AddItem(slot.item)) {
                std::cout << "[SystemLoot] +" << slot.item.quantity
                    << " x " << slot.item.itemId << std::endl;
            }
            else {
                std::cout << "[SystemLoot] INVENTAIRE PLEIN !" << std::endl;
            }
        }
        else {
            std::cout << "[SystemLoot] Échec drop : " << slot.item.itemId << std::endl;
        }
    }
}
