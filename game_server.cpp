#include "glfw_tools.h"
#include "game_draw.h"
#include "diego/zmqcpp/zmq.hpp"
//#include "game_status.pb.h"
#include "zmqcpp_msgs.h"
#include "game_zmq.h"
#include <sstream>
#include <string>

std::string get_game_status(const Game& game){
	//protobuf serialization of Game here
	return "Hello";
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
        	std::cout<<com;
        }

		// RECEIVE AND EXECUTE COMMANDS while incoming command
		// 6. Receive zmq_message
		// 7. convert to std::string get_str(zmq_message)
		// 8. Deserialize (id: int, speed: float, angle: float) with ProtoBuf
		// 9. Assign to player:
		//		game.players[id].speed = speed;
    	//		game.players[id].angle = angle;
    	game.players[0].speed = 10;

		glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
