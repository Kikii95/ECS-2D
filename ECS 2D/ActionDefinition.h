#pragma once
#include <string>

enum class ActionType {
    Use,
    Gather,
    Inspect,
    Interact
};

struct ActionData {
    std::string id;         
    std::string name;       
    ActionType type;        
    std::string targetType; 
    std::string effectId;   
    std::string itemId;     
    int value = 0;          
};
