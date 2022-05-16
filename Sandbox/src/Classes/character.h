#ifndef CHARACTER_H
#define CHARACTER_H

#include <Classes/sprite.h>

#include <Components/controller.h>
#include <Components/movement_component.h>

namespace gfl {

	class Character : public Sprite
	{
		friend class Application;
	public:
		Character();
		~Character() override;

	protected:
		void on_fixed_update(const float delta_time) override;
		void on_update(const float delta_time) override;

	public:
		Controller* controller;
		MovementComponent* movementComponent;
	};
}

#endif
