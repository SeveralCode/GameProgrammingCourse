#ifndef COMPONENT_H
#define COMPONENT_H

#include "object.h"
#include "tickable.h"

class Component : public Object, public ITickable
{
	friend class GameObject;
public:
	Component(const std::string name, const bool is_active = true) : Object(name, is_active){}
	virtual ~Component() = default;

	[[nodiscard]] GameObject* get_owner()const { return owner; }

protected:
	// Inherited via ITickable
	virtual void on_update(const float delta_time) override;
	virtual void on_fixed_update(const float delta_time) override;

private:
	GameObject* owner = nullptr;
};

#endif // !COMPONENT_H
