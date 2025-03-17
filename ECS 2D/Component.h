#pragma once
#include <typeindex>
#include "Entity.h"

class Entity;

class Component {
protected:
    Entity* m_pEntity;

public:
    explicit Component(Entity* _pEntity);
    virtual ~Component();

    int GetID() const;
    virtual void Logs();

    Entity* GetEntity();

    virtual std::type_index GetType() const = 0;
};
