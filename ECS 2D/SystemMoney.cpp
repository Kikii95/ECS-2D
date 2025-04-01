#include "SystemMoney.h"
#include <iostream>

SystemMoney::SystemMoney() {}

void SystemMoney::Update(float dt, const std::vector<Entity*>& entities) {
}

bool SystemMoney::Pay(Entity* entity, int amount) {
    auto* money = entity->GetComponent<ComponentMoney>();
    if (!money) return false;
    return money->Spend(amount);
}

void SystemMoney::Give(Entity* entity, int amount) {
    auto* money = entity->GetComponent<ComponentMoney>();
    if (money) money->Add(amount);
}

int SystemMoney::Get(Entity* entity) const {
    auto* money = entity->GetComponent<ComponentMoney>();
    return money ? money->GetBalance() : 0;
}
