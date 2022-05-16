#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <component.h>

#include <SFML/Graphics.hpp>

/**
 * \brief A component responsable for managing device inputs
 */
class Controller : public Component
{
	friend class Application;
	friend class MovementComponent;
public:
	Controller();
	~Controller() override;

	/**
	 * \brief get all axis component as 2D vector
	 * \return axis vector
	 */
	[[nodiscard]]sf::Vector2f get_axis_vector()const { return {XAxis, YAxis}; }

protected:
	void on_update(const float delta_time) override;
	void on_fixed_update(const float delta_time) override;

private:
	bool forwardMovement;
	bool rightwardMovement;
	float XAxis, YAxis;
};

#endif
