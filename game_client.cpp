#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include "diego/zmqcpp/zmq.hpp"
//#include "game_status.pb.h"
#include "zmqcpp_msgs.h"

int main(){
	
	//1. Set zmq subscriber to game status
	zmq::context_t context;
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:12345");
    const char *filter = "";
    subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

	// . Set zmq pusher to send client commands
	zmq::socket_t sender(context, ZMQ_PUSH);
    sender.connect("tcp://localhost:12346");
	while(1){
		zmq::message_t update;
        subscriber.recv(&update);
        std::string msg=get_str(update);
        std::cout<<msg;
		//3. Get game status, with Protobuf from stream
		//4. obtain ball coordinates(bx, by)

		//for each player
		for (int i = 0; i < 10; i++){
			std::string com = "command";
			zmq::message_t zmsg;
            get_msg(com, zmsg);
            sender.send(zmsg);
			//5. obtain player i (x,y)
			//6. compute angle of movement
			//	 float angle = 3.14 + atan2(y - by, x - bx);

			//7. Create "Command" msg, assign (id, speed, angle)
			//8. Serialize Command to std::string, then to zmq_message
			//9. Send message to server
		}
	}
	return 0;
}
