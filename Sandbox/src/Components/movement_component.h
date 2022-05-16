#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <component.h>
#include <Components/rect_transform.h>
#include <Components/controller.h>

/**
 * \brief A component to move transformable object inside the world scene
 */
class MovementComponent : public Component
{
public:
	MovementComponent();
	~MovementComponent() override;

	float speed;

	[[nodiscard]] sf::Vector2f get_velocity()const;
	[[nodiscard]] sf::Vector2f get_motion_vector()const;

	[[nodiscard]] bool motion_is_valid()const { return (inputController->forwardMovement || inputController->rightwardMovement); }

	Controller* inputController;
	RectTransform* transform;		// game object transform for motion 


	void on_update(const float delta_time) override;


};

#endif
