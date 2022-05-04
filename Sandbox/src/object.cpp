#include "object.h"

Object::Object(const std::string name, bool is_active)
{
	this->name = name;
	this->is_active = is_active;
}
