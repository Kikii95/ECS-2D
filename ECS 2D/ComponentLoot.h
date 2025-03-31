#pragma once
#include "Component.h"
#include <string>
#include <vector>

struct LootItem {
    std::string itemType;
    int quantity;
	float lootRate;

    LootItem(const std::string& type, int qty, float lrate)
        : itemType(type), quantity(qty), lootRate(lootRate) {
    }
};

class ComponentLoot : public Component {
public:
    ComponentLoot(Entity* entity);

    void AddItem(const LootItem& item);
    void RemoveItem(const std::string& type);
    const std::vector<LootItem>& GetLootItems() const;

    void SetLootable(bool value);
    bool IsLootable() const;

	void SetLootRate(float rate);
	float GetLootRate() const;

private:
    std::vector<LootItem> lootItems;
    bool isLootable = true;
};
