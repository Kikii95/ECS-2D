#pragma once
#include "Component.h"
#include <string>
#include <vector>

struct MerchantItem {
    std::string itemType;
    int price; 
    int quantity;

    MerchantItem(const std::string& type, int price, int qty)
        : itemType(type), price(price), quantity(qty) {
    }
};

class ComponentMerchant : public Component {
public:
    ComponentMerchant(Entity* entity, float buyRate = 1.0f, float sellRate = 1.0f);

    void AddItem(const MerchantItem& item);
    void RemoveItem(const std::string& itemType);

    const std::vector<MerchantItem>& GetStock() const;

    float GetBuyRate() const;
    float GetSellRate() const;

    void SetBuyRate(float rate);
    void SetSellRate(float rate);

private:
    std::vector<MerchantItem> stock;
    float buyRate; 
    float sellRate; 
};
