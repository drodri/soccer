#pragma once

class Vector2D  {
public: 
	float x;
	float y;

	Vector2D(float xv=0.0f,float yv=0.0f); 
	virtual ~Vector2D();

	float modulo();		
	float argumento();		
	Vector2D Unitario();		
	Vector2D operator - (const Vector2D &)const ;
	Vector2D operator + (const Vector2D &)const ;	
	float operator *(const Vector2D &)const ;	
	Vector2D operator *(float)const ;
};



