#include "area2d.h"

Area2D::Area2D() : GameObject("Area 2D")
{
	rect_transform = new RectTransform();
	rect_transform->set_scale(32, 32);
	rect_transform->get_transform()->setFillColor(sf::Color::White);

	add_component(rect_transform);
}

Area2D::~Area2D()
{
	delete rect_transform;
}

