template <typename T, typename... Args>
T* SystemManager::AddSystem(Args&&... args) {
    static_assert(std::is_base_of<System, T>::value, "T doit être un sous-type de System");

    std::type_index typeIdx(typeid(T));

    if (systems.find(typeIdx) != systems.end()) {
        return static_cast<T*>(systems[typeIdx].get());
    }

    auto system = std::make_unique<T>(std::forward<Args>(args)...);
    T* systemPtr = system.get();
    systems[typeIdx] = std::move(system);
    return systemPtr;
}


template <typename T>
T* SystemManager::GetSystem() {
    std::type_index typeIdx(typeid(T));
    auto it = systems.find(typeIdx);
    return (it != systems.end()) ? static_cast<T*>(it->second.get()) : nullptr;
}
