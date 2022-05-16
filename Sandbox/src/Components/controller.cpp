#include "controller.h"

Controller::Controller() : Component("Controller")
{
	forwardMovement = false;
	rightwardMovement = true;
	XAxis = 0;
	YAxis = 0;
}

Controller::~Controller() = default;

void Controller::on_update(const float delta_time)
{
	Component::on_update(delta_time);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forwardMovement = true;
		YAxis = -1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		forwardMovement = true;
		YAxis = 1;
	}
	else
	{
		forwardMovement = false;
		YAxis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightwardMovement = true;
		XAxis = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rightwardMovement = true;
		XAxis = -1;
	}
	else
	{
		forwardMovement = false;
		XAxis = 0;
	}

	printf("axis: %f, %f \n", XAxis, YAxis);
}

void Controller::on_fixed_update(const float delta_time)
{
	Component::on_fixed_update(delta_time);
}





