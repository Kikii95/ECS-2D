#pragma once

#include "System.h"

class SystemManager {
private:
    std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
    std::vector<System*> activeSystems;
    std::vector<System*> renderSystems;

public:
    ~SystemManager() = default;

    template <typename T, typename... Args>
    T* AddSystem(Args&&... args);

    template <typename T>
    T* GetSystem();

    void Update(float dt);
    void UpdateRender(float dt);
};

#include "SystemManager.inl"
