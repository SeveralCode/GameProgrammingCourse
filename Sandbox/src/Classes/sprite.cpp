#include "sprite.h"

namespace gfl {

	Sprite::Sprite() : Area2D()
	{
		renderer = new Renderer2D();
		add_component(renderer);
	}

	Sprite::~Sprite()
	{
		delete rect_transform;
		delete renderer;
	}
}

