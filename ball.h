#pragma once
#include "body.h"

struct Ball: public Body{
	Ball() :Body(50, 25){
		speed = 0;
		angle = 0;
		radius = 1;
	}
};
