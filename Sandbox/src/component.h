#ifndef COMPONENT_H
#define COMPONENT_H

#include "object.h"
#include "tickable.h"

class Component : public Object, public ITickable
{
	friend class GameObject;
public:
	Component(const std::string name, const bool is_active = true) : Object(name, is_active){}
protected:
	// Inherited via ITickable
	virtual void on_update(const float delta_time) override;
	virtual void on_fixed_update(const float delta_time) override;
};

#endif // !COMPONENT_H
