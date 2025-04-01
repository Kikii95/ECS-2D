#pragma once
#include <string>

enum class ItemType {
    Generic,
    Weapon,
    Consumable,
    Resource,
    Trophy,
    QuestItem
};

enum class AreaType {
    None,
    Line,
    Arc,
    Cone,
    Circle
};

struct ItemDefinition {
    // Identité
    std::string id;
    std::string name;
    std::string description;

    // General
    ItemType type = ItemType::Generic;
    float weight = 0.0f;
    int basePrice = 0;
    bool stackable = true;

    // Combat 
    int damage = 0;
    int range = 1;
    int penetration = 0;             
    AreaType area = AreaType::None; 
    int areaSize = 1;               

    // Effect
    std::string effectId;           // poison, burn, heal

	// Consumable
    int healAmount = 0;             
};
