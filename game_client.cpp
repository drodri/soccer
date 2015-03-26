#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include "diego/zmqcpp/zmq.hpp"
//#include "game_status.pb.h"
#include "zmqcpp_msgs.h"

int main(){
	
	while(1){
		//Get game status
		//first obtain ball (bx, by)

		//for each player
		for (int i = 0; i < 10; i++){
			// obtain player i (x,y)
			//float angle = 3.14 + atan2(y - by, x - bx);
			
			//send ID, angle, speed=10
		}
	}
	return 0;
}
