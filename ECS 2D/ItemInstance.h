#pragma once
#include <string>

struct ItemInstance {
    std::string itemId;  
    int quantity = 1;

    float durability = 100.0f; 
    bool identified = true;    
    bool equipped = false;     

    ItemInstance(const std::string& id, int qty = 1)
        : itemId(id), quantity(qty) {
    }
};
