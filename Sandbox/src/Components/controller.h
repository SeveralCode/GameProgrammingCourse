#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <component.h>

#include <SFML/Graphics.hpp>

/**
 * \brief handles user input
 */
class Controller : public Component
{
	friend class Application;
public:
	Controller();
	~Controller() override;

protected:
	void on_update(const float delta_time) override;
	void on_fixed_update(const float delta_time) override;
	virtual void on_input(sf::Keyboard::Key input[2]);
};

#endif
