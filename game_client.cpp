#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include "diego/zmqcpp/zmq.hpp"
#include "game_status.pb.h"
#include "zmqcpp_msgs.h"


int main(int argc, char* argv[]){
	zmq::context_t context;
	zmq::socket_t subscriber(context, ZMQ_SUB);
	subscriber.connect("tcp://localhost:12345");

	const char *filter = "";
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

	while(1){
		zmq::message_t update;
		subscriber.recv(&update);

		soccer::GameStatus game_msg;
		game_msg.ParseFromString(get_str(update));
		std::cout << game_msg.DebugString();

		float bx = game_msg.ball().x();
		float by = game_msg.ball().y();
		for (int i = 0; i < 10; i++){
			float x = game_msg.player(i).x();
			float y = game_msg.player(i).y();
			float angle = 3.14 + atan2(y - by, x - bx);
			
			//send ID, angle, speed=10
		}
	}
	return 0;
}
