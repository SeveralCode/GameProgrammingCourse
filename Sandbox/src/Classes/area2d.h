#ifndef AREA2D_H
#define AREA2D_H

// classes
#include <Classes/game_object.h>

/*components*/
#include <Components/rect_transform.h>

class Area2D : public GameObject
{
public:
	Area2D();
	~Area2D() override;

	RectTransform* rect_transform;
};

#endif
