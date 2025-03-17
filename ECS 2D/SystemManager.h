#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "System.h"

//class System;

class SystemManager {
private:
    std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

public:
    ~SystemManager() = default; // Gestion automatique via unique_ptr

    template <typename T, typename... Args>
    T* AddSystem(Args&&... args);

    template <typename T>
    T* GetSystem();

    void Update(float dt);
    void UpdateRender(float dt);
};

#include "SystemManager.inl"
