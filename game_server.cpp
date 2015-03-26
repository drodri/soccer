#include "glfw_tools.h"
#include "game_draw.h"
#include "diego/zmqcpp/zmq.hpp"
//#include "game_status.pb.h"
#include "zmqcpp_msgs.h"
#include "game_zmq.h"
#include <sstream>
#include <string>

int main(){
	GLFWwindow* window = InitGLFW(800, 600);
	Game game;

	double time_ini = glfwGetTime();
    while (!glfwWindowShouldClose(window)){
		updateWorldView(window);
		double time2 = glfwGetTime();
		game.Move((time2-time_ini));
		time_ini = time2;
		draw(game);

		glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
