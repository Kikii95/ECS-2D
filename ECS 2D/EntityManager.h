#pragma once

#include "Entity.h"
#include <functional>
#include "ItemDefinition.h"
#include "HexDirection.h"


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
    std::vector<Entity*> GetEntitiesInArea(const sf::Vector2i& center, AreaType type, int size, HexDirection direction, std::function<bool(Entity*)> filter);
    
    void DestroyEntity(int id);

    void Clear();
};
