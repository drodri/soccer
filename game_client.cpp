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
	zmq::socket_t sender(context, ZMQ_PUSH);
	sender.connect("tcp://localhost:12346");

	const char *filter = "";
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

	while(1){
		zmq::message_t update;
		subscriber.recv(&update);

		soccer::GameStatus game_msg;
		std::istringstream input(get_str(update));
		game_msg.ParseFromIstream(&input);
		//std::cout << game_msg.DebugString();

		float bx = game_msg.ball().x();
		float by = game_msg.ball().y();
		for (int i = 0; i < 10; i++){
			float x = game_msg.player(i).x();
			float y = game_msg.player(i).y();
			float angle = 3.14 + atan2(y - by, x - bx);
			soccer::Command command_msg;
			command_msg.set_id(i);
			command_msg.set_angle(angle);
			command_msg.set_speed(10);
			std::ostringstream output;
			command_msg.SerializeToOstream(&output);
			zmq::message_t zmsg;
			get_msg(output.str(), zmsg);
			sender.send(zmsg);
		}
	}
	return 0;
}
