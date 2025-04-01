#include "SystemEvent.h"
#include <iostream>

SystemEvent::SystemEvent() {}

void SystemEvent::Update(float dt, const std::vector<Entity*>& entities) {
    for (auto* entity : entities) {
        auto* comp = entity->GetComponent<ComponentEvent>();
        if (!comp) continue;

        for (const auto& e : comp->GetEvents()) {
            if (comp->IsEventAvailable(e.id)) {
                TriggerEvent(entity, e.id);
                break;
            }
        }
    }
}

bool SystemEvent::TriggerEvent(Entity* entity, const std::string& eventId) {
    auto* comp = entity->GetComponent<ComponentEvent>();
    if (!comp || !comp->IsEventAvailable(eventId)) return false;

    comp->MarkAsTriggered(eventId);
    std::cout << "[SystemEvent] Événement déclenché : " << eventId << std::endl;

    return true;
}

bool SystemEvent::IsEventAvailable(Entity* entity, const std::string& eventId) {
    auto* comp = entity->GetComponent<ComponentEvent>();
    return comp && comp->IsEventAvailable(eventId);
}
