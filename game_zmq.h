#pragma once

#include "diego/zmqcpp/zmq.hpp"
#include "game_status.pb.h"
#include <sstream>
#include <string>

std::string fill_msg(const Game& game){
	soccer::GameStatus game_msg;
	for (int i = 0; i < game.players.size(); i++){
		soccer::Player* player = game_msg.add_player();
		player->set_id(i);
		player->set_x(game.players[i].x);
		player->set_y(game.players[i].y);
	}
	game_msg.mutable_ball()->set_x(game.ball.x);
	game_msg.mutable_ball()->set_y(game.ball.y);

	//cout << game_msg.DebugString();

	std::ostringstream output;
	game_msg.SerializeToOstream(&output);
	return output.str();
}
void execute_command(std::string msg, Game& game){
	soccer::Command command_msg;
	std::istringstream input(msg);
	command_msg.ParseFromIstream(&input);
	//std::cout << command_msg.DebugString();
	int id = command_msg.id();
	if (id < 0 || id >= 10)
		return;
	game.players[id].speed = command_msg.speed();
	game.players[id].angle = command_msg.angle();
}