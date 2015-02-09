#pragma once

#include "ball.h"
#include "player.h"
#include "field.h"
#include <vector>

struct Game{
	Field field;
	std::vector<Player> players;
	Ball ball;
	int score1, score2;

	Game(){
		score1 = score2 = 0;
		for (int i = 0; i < 5; i++){
			players.push_back(Player(2, 10*i));
		}
		for (int i = 5; i < 10; i++){
			players.push_back(Player(98, 10 * (i-5)));
		}
	}
	void Move(float t=0.025f){
		ball.Move(t);
		for (int i = 0; i < players.size(); i++){
			players[i].Move(t);
		}
		for (int i = 0; i < (int)players.size() - 1; i++){
			for (size_t j = i + 1; j < players.size(); j++){
				players[i].collision(players[j]);
			}
		}
		for (int i = 0; i < players.size(); i++){
			players[i].collision(ball);
		}
		if (ball.goal(field, score1, score2)){
			std::cout << "GOAL! Score: " << score1 << "-" << score2 << "\n";
		}
		ball.collision(field);
	}
};
