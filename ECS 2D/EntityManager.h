#pragma once

#include "Entity.h"


class EntityManager {
private:
    std::unordered_map<int, std::unique_ptr<Entity>> entities;
    int nextEntityID = 0;  

public:
    ~EntityManager() = default; 

    Entity* CreateEntity();

    Entity* GetEntity(int id);

    std::vector<Entity*> GetAllEntities();
    std::vector<Entity*> GetEntitiesByTag(const std::string& tag);
    
    void DestroyEntity(int id);

    void Clear();
};
