#include "ComponentAction.h"

ComponentAction::ComponentAction(Entity* entity)
    : Component(entity) {
}

void ComponentAction::AddAction(const ActionData& action) {
    for (auto& existing : actions) {
        if (existing.name == action.name) {
            existing = action; 
            return;
        }
    }
    actions.push_back(action);
}

void ComponentAction::RemoveAction(const std::string& name) {
    actions.erase(std::remove_if(actions.begin(), actions.end(),
        [&name](const ActionData& a) {
            return a.name == name;
        }), actions.end());
}

const std::vector<ActionData>& ComponentAction::GetActions() const {
    return actions;
}

const ActionData* ComponentAction::GetActionByName(const std::string& name) const {
    for (const auto& a : actions) {
        if (a.name == name) return &a;
    }
    return nullptr;
}
