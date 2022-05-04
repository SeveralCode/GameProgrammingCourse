#include "game_object.h"
#include "component.h"


GameObject::GameObject(const std::string name, const bool is_active) : Object(name, is_active)
{
	this->name = name;
	this->is_active = is_active;
}

GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool is_active) : Object(name, is_active)
{
	this->name = name;
	this->components = components;
	this->is_active = is_active;
}

GameObject::~GameObject()
{
}

void GameObject::add_component(Component* component)
{
	components.push_back(component);
}

void GameObject::remove_component(Component* component)
{
	//components.erase()
}

void GameObject::on_fixed_update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->is_active && item->tick_enabled()) { item->on_fixed_update(delta_time); }
	}
}

void GameObject::on_update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->is_active && item->tick_enabled()) { item->on_update(delta_time); }
	}
}
