#include "ComponentRessource.h"
#include "ToolBox.h"

ComponentRessource::ComponentRessource(Entity* entity, const std::string& type, int qty, float unitW)
    : Component(entity), ressourceType(type), quantity(qty), unitWeight(unitW) {
}

void ComponentRessource::SetType(const std::string& type) {
    ressourceType = type;
}

std::string ComponentRessource::GetRessourceType() const {
    return ressourceType;
}

void ComponentRessource::SetQuantity(int qty) {
    quantity = maximum(0, qty);
}

int ComponentRessource::GetQuantity() const {
    return quantity;
}

void ComponentRessource::Add(int amount) {
    quantity += amount;
}

void ComponentRessource::Remove(int amount) {
    quantity = maximum(0, quantity - amount);
}

float ComponentRessource::GetTotalWeight() const {
    return unitWeight * quantity;
}

float ComponentRessource::GetUnitWeight() const {
    return unitWeight;
}

void ComponentRessource::SetUnitWeight(float weight) {
    unitWeight = maximum(0.0f, weight);
}
