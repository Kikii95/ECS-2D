#include "SystemManager.h"
#include "GameEngine.h" 
#include "SystemRender.h"

void SystemManager::Update(float dt) {
    const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();
    for (System* sys : activeSystems) {
        sys->Update(dt, entities);
    }
}

void SystemManager::UpdateRender(float dt) {
    const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();
    for (System* sys : renderSystems) {
        sys->Update(dt, entities);
    }
}
