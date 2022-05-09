#ifndef SPRITE_H
#define SPIRTE_H

#include <Classes/area2d.h>
#include <Components/renderer2D.h>

class Sprite : public Area2D
{
public:
	Sprite();
	~Sprite() override;

	Renderer2D* renderer;
};

#endif
