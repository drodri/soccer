#pragma once

#include "game.h"
#include <diego/glfw/include/GLFW/glfw3.h>


void draw(const Field& field){
	glBegin(GL_QUADS);          // Start Drawing Quads
		glColor3f(0.1, 0.7, 0.1);
		glNormal3f(0.0f, 0.0f, 1.0f);      // Normal Facing Forward
		glVertex3f(0, 0, 0);  // Bottom Left Of The Texture and Quad
		glVertex3f(0, field.height, 0);  // Bottom Right Of The Texture and Quad
		glVertex3f(field.width, field.height, 0);  // Top Right Of The Texture and Quad
		glVertex3f(field.width, 0, 0);  // Top Left Of The Texture and Quad
	glEnd();
	for (int i = 0; i < 2; i++){
		glBegin(GL_QUADS);          
			glColor3f(0.6, 0.2, 0.6);
			glNormal3f(0.0f, 0.0f, 1.0f);     
			glVertex3f(i*field.width, field.height/3, 0);  
			glVertex3f(i*field.width, field.height / 3, 5);
			glVertex3f(i*field.width, field.height*2. / 3,5);
			glVertex3f(i*field.width, field.height*2. / 3, 0);
		glEnd();
	}
	
}

void draw(const Ball& ball){
	GLUquadric* quadric = gluNewQuadric();      // Create A Pointer To The Quadric Object
	glPushMatrix();
		glTranslatef(ball.x, ball.y, ball.radius);

		glColor3f(1, 1, 0);
		gluSphere(quadric, ball.radius, 20, 20);        // Draw a Sphere
		gluDeleteQuadric(quadric); 
	glPopMatrix();
}

void draw(const Player& player){
	GLUquadric* quadric = gluNewQuadric();      // Create A Pointer To The Quadric Object
	glPushMatrix();
		glTranslatef(player.x, player.y, player.radius);
		gluSphere(quadric, player.radius, 20, 20);        // Draw a Sphere
		gluDeleteQuadric(quadric);
	glPopMatrix();
}

void draw(const Game& game){
	draw(game.field);
	for (int i = 0; i < game.players.size(); i++){
		if (i<game.players.size()/2)
			glColor3f(1, 0, 0);
		else
			glColor3f(1, 1, 1);
		draw(game.players[i]);
	}
	draw(game.ball);
}

