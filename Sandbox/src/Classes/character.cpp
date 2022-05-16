#include "character.h"


gfl::Character::Character() : Sprite()
{

	controller = new Controller();
	add_component(controller);

	movementComponent = new MovementComponent();
	movementComponent->inputController = controller;
	movementComponent->transform = rect_transform;
	movementComponent->speed = 120;
	add_component(movementComponent);

}

gfl::Character::~Character()
{
	delete movementComponent;
	delete controller;
}

void gfl::Character::on_fixed_update(const float delta_time)
{
	Sprite::on_fixed_update(delta_time);
}

void gfl::Character::on_update(const float delta_time)
{
	gfl::Sprite::on_update(delta_time);
}

