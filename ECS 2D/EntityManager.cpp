//#include "pch.h"
#include "EntityManager.h"

Entity* EntityManager::CreateEntity() {
    auto entity = std::make_unique<Entity>(nextEntityID);
    Entity* rawPtr = entity.get();
    entities.emplace(nextEntityID, std::move(entity)); 

    nextEntityID++;
    return rawPtr;
}

Entity* EntityManager::GetEntity(int id) {
    auto it = entities.find(id);
    return (it != entities.end()) ? it->second.get() : nullptr;
}

std::vector<Entity*> EntityManager::GetAllEntities() {
    std::vector<Entity*> entityList;
    entityList.reserve(entities.size()); 
    for (auto& pair : entities) {
        entityList.push_back(pair.second.get());
    }
    return entityList;
}

void EntityManager::DestroyEntity(int id) {
    entities.erase(id); 
}

void EntityManager::Clear() {
    entities.clear(); 
}
