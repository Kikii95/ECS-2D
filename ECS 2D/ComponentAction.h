#pragma once
#include "Component.h"
#include <string>
#include <vector>

enum class ActionType {
    Undefined,
    Attack,
    Heal,
    Repair,
    Buff,
    Debuff,
    Utility
};

struct ActionData {
    std::string name;
    ActionType type;
    int cost; 
    int range; 
    std::string description;

    ActionData(const std::string& n, ActionType t, int c, int r, const std::string& desc)
        : name(n), type(t), cost(c), range(r), description(desc) {
    }
};

class ComponentAction : public Component {
public:
    ComponentAction(Entity* entity);

    void AddAction(const ActionData& action);
    void RemoveAction(const std::string& name);

    const std::vector<ActionData>& GetActions() const;
    const ActionData* GetActionByName(const std::string& name) const;

private:
    std::vector<ActionData> actions;
};
