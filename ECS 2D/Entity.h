#pragma once

#include <SFML/Graphics.hpp>
#include "Logs.h"
#include <vector>
#include <list>
#include <unordered_map>
#include <typeindex>
#include <memory>

class Component;
class System;
class Script;

class Entity {
private:
    int m_id;
    std::unordered_map<std::type_index, Component*> m_components; // Accès rapide
	std::list<Script*> m_script;

public:
    Entity(int id);

    int GetID() const;

    template <typename T, typename... Args>
    T* AddComponent(Args&&... args);

    template <typename T>
    T* GetComponent();

    template <typename T>
	bool HasComponent();

    template <typename T>
    void RemoveComponent();

	void Destroy();

    void Update(float dt);

};

#include "Entity.inl"