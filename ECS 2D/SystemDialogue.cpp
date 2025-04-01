#include "SystemDialogue.h"
#include <iostream>

SystemDialogue::SystemDialogue() {}

void SystemDialogue::Update(float dt, const std::vector<Entity*>& entities) {
}

const DialogueEntry* SystemDialogue::GetAvailableDialogue(Entity* entity, const std::string& id) {
    auto* dialogue = entity->GetComponent<ComponentDialogue>();
    if (!dialogue) return nullptr;

    if (dialogue->IsDialogueAvailable(id)) {
        for (const auto& d : dialogue->GetDialogues()) {
            if (d.id == id)
                return &d;
        }
    }
    return nullptr;
}

void SystemDialogue::TriggerDialogue(Entity* entity, const std::string& id) {
    auto* dialogue = entity->GetComponent<ComponentDialogue>();
    if (!dialogue) return;

    if (dialogue->IsDialogueAvailable(id)) {
        const auto* entry = GetAvailableDialogue(entity, id);
        if (entry) {
            std::cout << "[SystemDialogue] " << entry->text << std::endl;
            dialogue->MarkAsConsumed(id);
        }
    }
    else {
        std::cout << "[SystemDialogue] Dialogue indisponible : " << id << std::endl;
    }
}
