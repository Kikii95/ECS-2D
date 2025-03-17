#include "SystemManager.h"
#include "GameEngine.h" 
#include "SystemRender.h"

void SystemManager::Update(float dt) {
    if (debugMode && logSystemManager) { HEAD("CLEAN") << LINE << ENDL2; }
    if (debugMode && logSystemManager)
        HEAD("sys_MANAGER") << "Mise a jour des systemes ECS" << ENDL;

    const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();

    if (debugMode && logSystemManager)
        HEAD("sys_MANAGER") << "Nombre d'entites recuperees dans Update() : " << int(entities.size()) << ENDL;

    for (auto& pair : systems) {
        if (!dynamic_cast<SystemRender*>(pair.second.get())) { // Exclut les systemes de rendu
            pair.second->Update(dt, entities);
        }
    }

    if (debugMode && logSystemManager)
        HEAD("sys_MANAGER") << "Mise a jour terminee" << ENDL;
}

void SystemManager::UpdateRender(float dt) {
    const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();

    for (auto& pair : systems) {
        if (dynamic_cast<SystemRender*>(pair.second.get())) {
            pair.second->Update(dt, entities);
        }
    }
}
