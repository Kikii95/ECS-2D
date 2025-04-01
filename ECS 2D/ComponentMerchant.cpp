#include "ComponentMerchant.h"
#include "ToolBox.h"

ComponentMerchant::ComponentMerchant(Entity* entity, float buyRate, float sellRate)
    : Component(entity), buyRate(buyRate), sellRate(sellRate) {
}

void ComponentMerchant::AddItem(const MerchantSlot& slot) {
    for (auto& existing : stock) {
        if (existing.item.itemId == slot.item.itemId && slot.item.quantity > 0) {
            existing.item.quantity += slot.item.quantity;
            return;
        }
    }
    stock.push_back(slot);
}

void ComponentMerchant::RemoveItem(const std::string& itemId) {
    stock.erase(std::remove_if(stock.begin(), stock.end(),
        [&itemId](const MerchantSlot& slot) {
            return slot.item.itemId == itemId;
        }), stock.end());
}

std::vector<MerchantSlot>& ComponentMerchant::GetStock() {
    return stock;
}

const std::vector<MerchantSlot>& ComponentMerchant::GetStock() const {
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
