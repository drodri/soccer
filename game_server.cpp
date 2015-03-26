#include "glfw_tools.h"
#include "game_draw.h"
#include "diego/zmqcpp/zmq.hpp"
#include "game_status.pb.h"
#include "zmqcpp_msgs.h"
#include "game_zmq.h"
#include <sstream>
#include <string>

std::string get_game_status(const Game& game){
	soccer::GameStatus game_msg;
	for (int i = 0; i < game.players.size(); i++){
        soccer::Player* player = game_msg.add_players();
        player->set_id(i);
        player->set_x(game.players[i].x);
        player->set_y(game.players[i].y);
    }
	game_msg.mutable_ball()->set_x(game.ball.x);
    game_msg.mutable_ball()->set_y(game.ball.y);
    std::string str;
	game_msg.SerializeToString(&str);
	return str;
}

int main(){
	GLFWwindow* window = InitGLFW(800, 600);
	Game game;

	//1. Setup broadcast server
	zmq::context_t context;
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:12345");
	//5. Setup command pull reciever
	zmq::socket_t receiver(context, ZMQ_PULL);
    receiver.bind("tcp://*:12346");

	double time_ini = glfwGetTime();
    while (!glfwWindowShouldClose(window)){
		updateWorldView(window);
		double time2 = glfwGetTime();
		game.Move((time2-time_ini));
		time_ini = time2;
		draw(game);

		//broadcast game current status
		//2. Serialize game into std::string with Protobuf
		std::string status=get_game_status(game);
        zmq::message_t zmsg;
        get_msg(status, zmsg);
        publisher.send(zmsg);

        zmq::message_t command;
        while (receiver.recv(&command, ZMQ_NOBLOCK)){
        	std::string com = get_str(command);
        	soccer::Command command_msg;
		    command_msg.ParseFromString(com);
		    //std::cout << command_msg.DebugString();
		    int id = command_msg.id();
		    if (id < 0 || id >= 10)
		        return -1;
		    game.players[id].speed = command_msg.speed();
		    game.players[id].angle = command_msg.angle();
        }


		glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
