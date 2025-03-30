#include "ComponentMerchant.h"
#include "ToolBox.h"

ComponentMerchant::ComponentMerchant(Entity* entity, float buyRate, float sellRate)
    : Component(entity), buyRate(buyRate), sellRate(sellRate) {
}

void ComponentMerchant::AddItem(const MerchantItem& item) {
    for (auto& existing : stock) {
        if (existing.itemType == item.itemType) {
            existing.quantity += item.quantity;
            return;
        }
    }
    stock.push_back(item);
}

void ComponentMerchant::RemoveItem(const std::string& itemType) {
    stock.erase(std::remove_if(stock.begin(), stock.end(),
        [&itemType](const MerchantItem& item) {
            return item.itemType == itemType;
        }), stock.end());
}

const std::vector<MerchantItem>& ComponentMerchant::GetStock() const {
    return stock;
}

float ComponentMerchant::GetBuyRate() const {
    return buyRate;
}

float ComponentMerchant::GetSellRate() const {
    return sellRate;
}

void ComponentMerchant::SetBuyRate(float rate) {
    buyRate = maximum(0.1f, rate);
}

void ComponentMerchant::SetSellRate(float rate) {
    sellRate = maximum(0.1f, rate);
}
