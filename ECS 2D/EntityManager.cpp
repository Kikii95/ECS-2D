//#include "pch.h"
#include "EntityManager.h"
#include "ComponentTag.h"

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

std::vector<Entity*> EntityManager::GetEntitiesByTag(const std::string& tag) {
    std::vector<Entity*> result;
    for (auto& pair : entities) {
        Entity* entity = pair.second.get(); 
        ComponentTag* tagComp = entity->GetComponent<ComponentTag>();
        if (tagComp && tagComp->GetTag() == tag) {
            result.push_back(entity);
        }
    }
    return result;
}

void EntityManager::DestroyEntity(int id) {
    entities.erase(id); 
}

void EntityManager::Clear() {
    entities.clear(); 
}
