#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object 
{
public:
	Object(const std::string name, bool is_active = true);

	void activate() { is_active = true; }
	void deactivate() { is_active = false; };
	bool has_activity()const { return is_active; }
	std::string get_name()const { return name; }


protected:
	bool is_active;
	std::string name;
};

#endif // !OBJECT_H
