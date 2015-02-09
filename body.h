#pragma once
#include <math.h>
#include <iostream>
#include "field.h"
using namespace std;
#include "vector2d.h"

struct Body{
	Body(float _x = 0, float _y = 0, float r = 2) :x(_x), y(_y), radius(r){
		r = g = b = 1;
		speed = 0;
		angle = 0;
		friction = 0.99f;
	}
	float radius;
	float x, y;
	float r, g, b;
	float speed;
	float angle;
	float friction;

	void Move(float t){
		if (speed > 10)
			speed = 10;
		if (speed < 0)
			speed = 0;
		x += speed * cos(angle) * t;
		y += speed * sin(angle) * t;
		speed *= friction;
	}
	void collision(Body& body){
		 //Vector que une los centros
		Vector2D dif = Vector2D(body.x, body.y) - Vector2D(x, y);
		float d = dif.modulo();
		float dentro = d-(radius+body.radius);

		if (dentro >= 0.0f) {//si no hay colision
			return;
		}
    
		//el argumento del vector que une los centros
		float angd = dif.argumento();
        
		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro/2*(float)cos(angd),dentro/2*(float)sin(angd));
		x += desp.x;
		y += desp.y;
		body.x -= desp.x;
		body.y -= desp.y;

		angd = angd-3.14159f/2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = angle - angd;
		float th2 = body.angle - angd;
        
		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = speed*(float)cos(th1);
		float u1y = speed*(float)sin(th1);
		float u2x = body.speed*(float)cos(th2);
		float u2y = body.speed*(float)sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = radius;
		float m2 = body.radius;
		float py = m1*u1y+m2*u2y;//Cantidad de movimiento inicial ejey
		float ey = m1*u1y*u1y+m2*u2y*u2y;//Energia cinetica inicial ejey
    
		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2*py*m2;
		float c = py*py-m1*ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0 ) disc = 0;
		//las nuevas velocidades segun el eje Y relativo
		float v2y=(-b+(float)sqrt(disc))/(2*a);
		float v1y=(py-m2*v2y)/m1;
        
		//Modulo y argumento de las velocidades en coordenadas absolutas
		speed=(float)sqrt(v1x*v1x+v1y*v1y);
		body.speed = (float)sqrt(v2x*v2x + v2y*v2y);
		angle=angd+(float)atan2(v1y,v1x);
		body.angle = angd + (float)atan2(v2y, v2x);

	}
	void collision(const Field& field){
		float vx = cos(angle);
		float vy = sin(angle);
		if (x < radius){
			vx = -vx;
			x = radius;
		}
		if (x + radius >= field.width){
			vx = -vx;
			x = field.width - radius;
		}
		if (y < radius){
			vy = -vy;
			y = radius;
		}
		if (y + radius>= field.height){
			vy = -vy;
			y = field.height - radius;
		}
		angle = atan2(vy, vx);
	}
	bool goal(const Field& field, int& score1, int& score2){
		if (x < radius && y > field.height/3 && y < field.height*2./3){
			x = field.width/2;
			y = field.height / 2;
			score1++;
			return true;
		}
		if (x +radius > field.width && y > field.height / 3 && y < field.height*2. / 3){
			x = field.width / 2;
			y = field.height / 2;
			score2++;
			return true;
		}
		return false;
	}
};