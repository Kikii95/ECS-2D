//#include "pch.h"
#include "Entity.h"

Entity::Entity(int id) : m_id(id) {}

int Entity::GetID() const {
	return m_id;
}

void Entity::Update(float dt) {}

void Entity::Destroy() {
}
