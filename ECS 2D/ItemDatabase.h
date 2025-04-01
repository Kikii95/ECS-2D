#pragma once
#include "ItemDefinition.h"
#include <unordered_map>
#include <string>

class ItemDatabase {
public:
    static ItemDatabase& Get();

    bool LoadFromJson(const std::string& path);
    void AddItem(const ItemDefinition& def);
    const ItemDefinition* GetItem(const std::string& id) const;

private:
    std::unordered_map<std::string, ItemDefinition> items;
};

ItemType StringToItemType(const std::string& typeStr);
std::string ItemTypeToString(ItemType type);