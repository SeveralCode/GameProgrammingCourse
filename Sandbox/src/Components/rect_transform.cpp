#include "Components/rect_transform.h"

RectTransform::RectTransform() : Component("Rect Transform")
{
	disable();	// disables update and fixed update callbacks

	position = sf::Vector2f(960, 540);
	rotation = 0;
	scale = sf::Vector2f(1, 1);

	transform = new sf::RectangleShape(scale);
}

RectTransform::RectTransform(const sf::Vector2f position, const float rotation, const sf::Vector2f scale) : Component("Rect Transform")
{
	disable();	// disables update and fixed update callbacks

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	transform = new sf::RectangleShape(scale);
}

RectTransform::~RectTransform()
{
	delete transform;
}

void RectTransform::set_position(const float x, const float y) const
{
	transform->setPosition(x, y);
}

void RectTransform::set_rotation(const float angle) const
{
	transform->setRotation(angle);
}

void RectTransform::set_scale(const float x, const float y) const
{
	transform->setScale(x, y);
}

sf::RectangleShape* RectTransform::get_transform() const
{
	return transform;
}



