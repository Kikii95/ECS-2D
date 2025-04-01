#pragma once
#include "ActionDefinition.h"
#include <unordered_map>
#include <string>

class ActionDatabase {
public:
    static ActionDatabase& Get();

    void LoadFromFile(const std::string& path);
    const ActionData* GetAction(const std::string& id) const;

private:
    std::unordered_map<std::string, ActionData> actions;
};
