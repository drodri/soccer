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
	return "";
}

int main(){
	GLFWwindow* window = InitGLFW(800, 600);
	Game game;

	//1. Setup broadcast server

	//5. Setup command pull reciever

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
		//3. Convert string to zmq message with:
		//   get_msg (const std::string& str, zmq::message_t& msg)
		//4. Send message broadcast

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
