#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "object.h"

class IDrawable 
{
	friend class Application;
public:
	IDrawable(const bool can_draw = true)
	{
		this->can_draw = can_draw;
	}

protected:
	virtual void on_draw() = 0;

protected:
	bool can_draw;
};

#endif