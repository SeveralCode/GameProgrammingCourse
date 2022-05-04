#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "object.h"
#include "tickable.h"

class Component;

/// <summary>
/// TODO: fornire descrizione decente
/// </summary>
class GameObject : public Object, public ITickable
{
	friend class Application;
public:
	GameObject(const std::string name, const bool is_active = true);
	GameObject(const std::string name, const std::vector<Component*> components, const bool is_active = true);
	~GameObject();

	/// <summary>
	/// add a components to this game object
	/// </summary>
	/// <param name="component">the component to add</param>
	void add_component(Component* component);
	
	/// <summary>
	/// removes a components from this object
	/// </summary>
	/// <param name="component">the components to remove</param>
	void remove_component(Component* component);
/*
	/// <summary>
	/// Get the first components of the given type from the attached components
	/// </summary>
	/// <typeparam name="T">the component to add</typeparam>
	/// <returns></returns>
	template<class T> const T* get_component()const {

		if (components.size == 0) return nullptr;

		for (T* item : components)
		{
			return item;
		}

		return nullptr;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<class T> std::vector<T*> get_components()const
	{
		std::vector<T*> result;
		
		if (components.size() == 0) return;

		for (T* item : components)
		{
			result.emplace_back(item);
		}

		return result;
	}*/

protected:
	// Inherited via ITickable
	virtual void on_fixed_update(const float delta_time) override;

	// Inherited via ITickable
	virtual void on_update(const float delta_time) override;

private:
	std::vector<Component*> components;

};

#endif