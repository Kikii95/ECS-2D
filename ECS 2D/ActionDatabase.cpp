#include "ActionDatabase.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

ActionDatabase& ActionDatabase::Get() {
    static ActionDatabase instance;
    return instance;
}

void ActionDatabase::LoadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "[ActionDatabase] Fichier introuvable : " << path << std::endl;
        return;
    }

    nlohmann::json json;
    in >> json;

    for (const auto& entry : json["actions"]) {
        ActionData action;
        action.id = entry.value("id", "");
        action.name = entry.value("name", "");
        std::string typeStr = entry.value("type", "");

        if (typeStr == "Use") action.type = ActionType::Use;
        else if (typeStr == "Gather") action.type = ActionType::Gather;
        else if (typeStr == "Inspect") action.type = ActionType::Inspect;
        else if (typeStr == "Interact") action.type = ActionType::Interact;

        action.targetType = entry.value("targetType", "");
        action.effectId = entry.value("effectId", "");
        action.itemId = entry.value("itemId", "");
        action.value = entry.value("value", 0);

        actions[action.id] = action;
    }

    std::cout << "[ActionDatabase] Chargé " << actions.size() << " actions depuis " << path << std::endl;
}

const ActionData* ActionDatabase::GetAction(const std::string& id) const {
    auto it = actions.find(id);
    return it != actions.end() ? &it->second : nullptr;
}
