#include "ItemDatabase.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

ItemDatabase& ItemDatabase::Get() {
    static ItemDatabase instance;
    return instance;
}

bool ItemDatabase::LoadFromJson(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Erreur d'ouverture : " << path << std::endl;
        return false;
    }

    json root;
    file >> root;

    if (!root.contains("items") || !root["items"].is_array()) {
        std::cerr << "Format JSON invalide : 'items' manquant ou incorrect." << std::endl;
        return false;
    }

    const auto& itemsArray = root["items"];
    for (const auto& entry : itemsArray) {
        ItemDefinition def;
        def.id = entry["id"];
        def.name = entry["name"];
        def.description = entry.value("description", "");
        def.type = StringToItemType(entry["type"]);
        def.weight = entry.value("weight", 0.0f);
        def.basePrice = entry.value("basePrice", 0);
        def.stackable = entry.value("stackable", true);
        def.damage = entry.value("damage", 0);
        def.range = entry.value("range", 0);
        def.healAmount = entry.value("healAmount", 0);
        def.effectId = entry.value("effectId", "");
        def.areaSize = entry.value("areaSize", 1);
        def.penetration = entry.value("penetration", 0);

        std::string areaStr = entry.value("area", "None");
        if (areaStr == "Arc")        def.area = AreaType::Arc;
        else if (areaStr == "Cone")  def.area = AreaType::Cone;
        else if (areaStr == "Circle")def.area = AreaType::Circle;
        else if (areaStr == "Line")  def.area = AreaType::Line;
        else                         def.area = AreaType::None;


        AddItem(def);
    }

    std::cout << "[ItemDatabase] " << items.size() << " objets chargés depuis " << path << std::endl;
    return true;
}

void ItemDatabase::AddItem(const ItemDefinition& def) {
    items[def.id] = def;
}

const ItemDefinition* ItemDatabase::GetItem(const std::string& id) const {
    auto it = items.find(id);
    return it != items.end() ? &it->second : nullptr;
}


ItemType StringToItemType(const std::string& typeStr) {
    if (typeStr == "Generic")    return ItemType::Generic;
    if (typeStr == "Weapon")     return ItemType::Weapon;
    if (typeStr == "Consumable") return ItemType::Consumable;
    if (typeStr == "Resource")   return ItemType::Resource;
    if (typeStr == "Trophy")     return ItemType::Trophy;
    if (typeStr == "QuestItem")  return ItemType::QuestItem;
    return ItemType::Generic; 
}

std::string ItemTypeToString(ItemType type) {
    switch (type) {
    case ItemType::Generic:    return "Generic";
    case ItemType::Weapon:     return "Weapon";
    case ItemType::Consumable: return "Consumable";
    case ItemType::Resource:   return "Resource";
    case ItemType::Trophy:     return "Trophy";
    case ItemType::QuestItem:  return "QuestItem";
    default: return "Unknown";
    }
}
