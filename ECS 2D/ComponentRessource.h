#pragma once
#include "Component.h"
#include <string>

class ComponentRessource : public Component {
public:
    ComponentRessource(Entity* entity, const std::string& type = "", int quantity = 0, float unitWeight = 0.0f);

    void SetType(const std::string& type);
    std::string GetRessourceType() const;

    void SetQuantity(int quantity);
    int GetQuantity() const;

    void Add(int amount);
    void Remove(int amount);

    float GetTotalWeight() const;
    float GetUnitWeight() const;
    void SetUnitWeight(float weight);

private:
    std::string ressourceType;
    int quantity;
    float unitWeight;
};
