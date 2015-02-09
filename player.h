#pragma once

#include "body.h"

struct Player: public Body{
	float real_speed, real_angle;
	Player(float _x = 0, float _y = 0, bool loc = false) :Body(_x, _y){
		real_speed = 0;
		real_angle = 0;
	}

	void Move(float t){
		real_speed += speed * t;
		if (real_speed > 12)
			real_speed = 12;
		if (real_speed < 0)
			real_speed = 0;

		const float PI = 3.14159;
		while (angle<-PI) angle += 2*PI;
		while (angle>PI) angle -= 2 * PI;
		while (real_angle<-PI) real_angle += 2 * PI;
		while (real_angle>PI) real_angle -= 2 * PI;

		float diff = real_angle - angle;
		if (real_angle - angle > PI)
			diff -= 2*PI ;
		if (real_angle - angle <-PI)
			diff -= 2*PI;

		real_angle -= diff *t;
		x += real_speed * cos(real_angle) * t;
		y += real_speed * sin(real_angle) * t;
		real_speed *= friction;
	}
};
