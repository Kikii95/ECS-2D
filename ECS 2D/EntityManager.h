#pragma once
#include <map>
#include <vector>
#include "Entity.h"
#include <memory>

class EntityManager {
private:
    std::unordered_map<int, std::unique_ptr<Entity>> entities;
    int nextEntityID = 0;  

public:
    ~EntityManager() = default; // Plus besoin d’un destructeur manuel

    Entity* CreateEntity();

    Entity* GetEntity(int id);

    std::vector<Entity*> GetAllEntities();

    void DestroyEntity(int id);

    void Clear();
};
