//#include "pch.h"
#include "SystemManager.h"
//#include "GameEngine.h" 

void SystemManager::Update(float dt) {
    //if (debugMode && logSystemManager) { HEAD("CLEAN") << LINE << ENDL2; }
    //if (debugMode && logSystemManager)
    //    HEAD("sys_MANAGER") << "Mise à jour des systèmes ECS" << ENDL;

    //const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();

    //if (debugMode && logSystemManager)
    //    HEAD("sys_MANAGER") << "Nombre d'entités récupérées dans Update() : " << int(entities.size()) << ENDL;

    //for (auto& pair : systems) {
    //    if (!dynamic_cast<SystemRender*>(pair.second.get())) { // Exclut les systèmes de rendu
    //        pair.second->Update(dt, entities);
    //    }
    //}

    //if (debugMode && logSystemManager)
    //    HEAD("sys_MANAGER") << "Mise à jour terminée" << ENDL;
}

void SystemManager::UpdateRender(float dt) {
    //const auto& entities = GameEngine::GetInstance().GetEntityManager().GetAllEntities();

    //for (auto& pair : systems) {
    //    if (dynamic_cast<SystemRender*>(pair.second.get())) {
    //        pair.second->Update(dt, entities);
    //    }
    //}
}
