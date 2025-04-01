#include "SystemInventory.h"
#include "ItemDatabase.h"
#include <iostream>

SystemInventory::SystemInventory() {}

void SystemInventory::Update(float dt, const std::vector<Entity*>& entities) {
}

bool SystemInventory::TransferItem(Entity* from, Entity* to, const std::string& itemId, int quantity) {
    auto* invFrom = from->GetComponent<ComponentInventory>();
    auto* invTo = to->GetComponent<ComponentInventory>();
    if (!invFrom || !invTo) return false;

    const auto& items = invFrom->GetItems();
    for (const auto& item : items) {
        if (item.itemId == itemId && item.quantity >= quantity) {
            ItemInstance transfer(itemId, quantity);

            if (!invTo->AddItem(transfer)) return false;

            invFrom->RemoveItem(itemId, quantity);

            std::cout << "[SystemInventory] Transfert réussi : " << quantity << " x " << itemId << std::endl;
            return true;
        }
    }

    std::cout << "[SystemInventory] Échec transfert : pas assez de " << itemId << std::endl;
    return false;
}
