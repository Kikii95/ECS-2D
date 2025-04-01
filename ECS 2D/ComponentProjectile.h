#pragma once
#include "Component.h"
#include "HexDirection.h"
#include <string>
#include <SFML/System/Vector2.hpp>

class ComponentProjectile : public Component {
public:
    std::string itemId;
    Entity* owner = nullptr;

    sf::Vector2i gridPos;         
    HexDirection direction;      
    int rangeLeft = 0;            
    int hitsRemaining = 1;        

    ComponentProjectile(Entity* entity);
};



//TO DO : ajouter dice effect (dégâts aléatoires) 