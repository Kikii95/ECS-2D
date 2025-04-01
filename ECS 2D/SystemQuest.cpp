#include "SystemQuest.h"
#include <iostream>

SystemQuest::SystemQuest() {}

void SystemQuest::Update(float dt, const std::vector<Entity*>& entities) {
}

bool SystemQuest::CompleteQuestStep(Entity* entity, const std::string& questId, int stepIndex) {
    auto* quest = entity->GetComponent<ComponentQuest>();
    if (!quest) return false;

    quest->CompleteStep(questId, stepIndex);

    std::cout << "[SystemQuest] Étape " << stepIndex << " complétée pour la quête " << questId << std::endl;

    QuestData* q = quest->GetQuest(questId);
    if (q) {
        bool allDone = true;
        for (const auto& step : q->steps) {
            if (!step.completed) {
                allDone = false;
                break;
            }
        }
        if (allDone) {
            q->status = QuestStatus::Completed;
            std::cout << "[SystemQuest] Quête " << questId << " terminée !" << std::endl;
        }
    }

    return true;
}

void SystemQuest::SetQuestStatus(Entity* entity, const std::string& questId, QuestStatus status) {
    auto* quest = entity->GetComponent<ComponentQuest>();
    if (quest) {
        quest->SetQuestStatus(questId, status);
    }
}

QuestStatus SystemQuest::GetQuestStatus(Entity* entity, const std::string& questId) {
    auto* quest = entity->GetComponent<ComponentQuest>();
    if (!quest) return QuestStatus::Inactive;

    QuestData* q = quest->GetQuest(questId);
    return q ? q->status : QuestStatus::Inactive;
}
