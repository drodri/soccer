#include "glfw_tools.h"
#include "game_draw.h"
#include "diego/zmqcpp/zmq.hpp"
#include "game_status.pb.h"
#include "zmqcpp_msgs.h"
#include "game_zmq.h"
#include <sstream>
#include <string>


int main(void){
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	GLFWwindow* window = InitGLFW(800, 600);

	Game game;
	//  Prepare our context and publisher
	zmq::context_t context;
	zmq::socket_t publisher(context, ZMQ_PUB);
	publisher.bind("tcp://*:12345");
	zmq::socket_t receiver(context, ZMQ_PULL);
	receiver.bind("tcp://*:12346");
	double time_ini = glfwGetTime();
    while (!glfwWindowShouldClose(window)){
		updateWorldView(window);
		double time2 = glfwGetTime();
		game.Move((time2-time_ini));
		time_ini = time2;
		draw(game);
		std::string msg = fill_msg(game);
		zmq::message_t zmsg;
		get_msg(msg, zmsg);
		publisher.send(zmsg);
		zmq::message_t command;
		while (receiver.recv(&command, ZMQ_NOBLOCK))
			execute_command(get_str(command), game);

		glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
