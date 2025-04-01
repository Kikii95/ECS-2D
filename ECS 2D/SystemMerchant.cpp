#include "SystemMerchant.h"
#include "ItemDatabase.h"
#include "ComponentMoney.h"
#include <iostream>

SystemMerchant::SystemMerchant() {}

void SystemMerchant::Update(float dt, const std::vector<Entity*>& entities) {
}

bool SystemMerchant::BuyItem(Entity* buyer, Entity* merchant, const std::string& itemId, int quantity) {
    auto* merch = merchant->GetComponent<ComponentMerchant>();
    auto* buyerInv = buyer->GetComponent<ComponentInventory>();
    auto* buyerMoney = buyer->GetComponent<ComponentMoney>();
    if (!merch || !buyerInv || !buyerMoney) return false;

    auto& stock = merch->GetStock();
    for (auto& slot : stock) {
        if (slot.item.itemId == itemId && slot.item.quantity >= quantity) {
            int price = GetItemPrice(slot, merch->GetBuyRate()) * quantity;

            if (!buyerMoney->Has(price)) {
                std::cout << "[SystemMerchant] Pas assez d’or ! (" << buyerMoney->GetBalance() << "/" << price << ")" << std::endl;
                return false;
            }

            ItemInstance toBuy(itemId, quantity);
            if (buyerInv->AddItem(toBuy)) {
                slot.item.quantity -= quantity;
                buyerMoney->Spend(price);
                std::cout << "[SystemMerchant] Achat : " << quantity << " x " << itemId << " pour " << price << " or" << std::endl;
                return true;
            }
        }
    }

    std::cout << "[SystemMerchant] Achat échoué." << std::endl;
    return false;
}


bool SystemMerchant::SellItem(Entity* seller, Entity* merchant, const std::string& itemId, int quantity) {
    auto* merch = merchant->GetComponent<ComponentMerchant>();
    auto* sellerInv = seller->GetComponent<ComponentInventory>();
    auto* sellerMoney = seller->GetComponent<ComponentMoney>();
    if (!merch || !sellerInv || !sellerMoney) return false;

    const ItemDefinition* def = ItemDatabase::Get().GetItem(itemId);
    if (!def) return false;

    int basePrice = def->basePrice;
    int finalPrice = static_cast<int>(basePrice * merch->GetSellRate() * quantity);

    if (sellerInv->RemoveItem(itemId, quantity)) {
        merch->AddItem(MerchantSlot(ItemInstance(itemId, quantity)));
        sellerMoney->Add(finalPrice);
        std::cout << "[SystemMerchant] Vente : " << quantity << " x " << itemId << " pour " << finalPrice << " or" << std::endl;
        return true;
    }

    return false;
}


int SystemMerchant::GetItemPrice(const MerchantSlot& slot, float rate) const {
    const ItemDefinition* def = ItemDatabase::Get().GetItem(slot.item.itemId);
    int basePrice = def ? def->basePrice : 0;
    return static_cast<int>((slot.overridePrice > 0 ? slot.overridePrice : basePrice) * rate);
}
