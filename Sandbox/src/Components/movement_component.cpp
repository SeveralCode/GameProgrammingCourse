#include "movement_component.h"

#include "Classes/game_object.h"

MovementComponent::MovementComponent() : Component("Movement Component")
{
	speed = 10;
}

MovementComponent::~MovementComponent()
{
	delete inputController;
	delete transform;
}

sf::Vector2f MovementComponent::get_velocity()const
{
	auto motion = inputController->get_axis_vector();
	return { motion.x * speed, motion.y * speed };
}

sf::Vector2f MovementComponent::get_motion_vector()const
{
	const auto velocity = get_velocity();
	const float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	if (length == 0.0f) return { 0,0 };

	return {velocity.x / length, velocity.y / length };
}

void MovementComponent::on_update(const float delta_time)
{
	if (!motion_is_valid()) return;

	auto nextPosition = transform->get_transform()->getPosition() + sf::Vector2f(get_motion_vector().x * speed * delta_time, get_motion_vector().y * speed * delta_time);

	printf("new pos: %f, %f\n", nextPosition.x, nextPosition.y);
	transform->set_position(nextPosition.x, nextPosition.y);
}




