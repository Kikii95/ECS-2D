#pragma once
#include "Component.h"
#include "ItemInstance.h"
#include <vector>

struct MerchantSlot {
    ItemInstance item;
    int overridePrice = -1; 

    MerchantSlot(const ItemInstance& item, int price = -1)
        : item(item), overridePrice(price) {
    }
};

class ComponentMerchant : public Component {
public:
    ComponentMerchant(Entity* entity, float buyRate = 1.0f, float sellRate = 1.0f);

    void AddItem(const MerchantSlot& slot);
    void RemoveItem(const std::string& itemId);

    std::vector<MerchantSlot>& GetStock(); 
    const std::vector<MerchantSlot>& GetStock() const; 


    float GetBuyRate() const;
    float GetSellRate() const;

    void SetBuyRate(float rate);
    void SetSellRate(float rate);

private:
    std::vector<MerchantSlot> stock;
    float buyRate;
    float sellRate;
};
