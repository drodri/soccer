#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include "diego/zmqcpp/zmq.hpp"
//#include "game_status.pb.h"
#include "zmqcpp_msgs.h"

int main(){
	
	//1. Set zmq subscriber to game status

	// . Set zmq pusher to send client commands
	while(1){
		//2. Get zmq_msg, conver to string
		//3. Get game status, with Protobuf from stream
		//4. obtain ball coordinates(bx, by)

		//for each player
		for (int i = 0; i < 10; i++){
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
