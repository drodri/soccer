
[![Build Status](https://webapi.biicode.com/v1/badges/diego/diego/soccer/master)](https://www.biicode.com/diego/soccer) 

# Getting started to ZMQ and Google Protocol Buffers in C/C++ with a soccer game

This project builds a distributed application, with a server graphical application, using the **GLFW** library that simulates a small soccer match (5 vs 5). That application will broadcast with the PUB-SUB scheme to N clients that will connect to it, receiving the basic status of the match, a message with coordinates of all players and the ball.

Those clients (one per player, though for demostration the current client controls the 10 players) can send a command to the server through a PUSH-PULL scheme.

The messages are encoded in binary format with Google Protocol Buffers (protobuf). The code might not be very correct or SW engineering, I just went straight to the goal without caring too much about it. Please feel free to contribute in the github repo.


After downloading and installing biicode, run:

	$ bii init myproject
	$ cd myproject
	$ bii open diego/soccer
	$ bii cpp:configure 

If in windows you should use VS 12 or other VS instead, as LibZMQ does not build with MinGW.

	$ bii cpp:configure -G "Visual Studio 12" 

Then, build and run the server:

	$ bii cpp:build
	$ bin\diego_soccer_game_server


![Match](https://webapi.biicode.com/v1/raw/diego/diego/soccer/master/0/match.png)


Then, in another console, move to your project folder and run the client:

	$ bin\diego_soccer_game_client

Remember if you want to change your messages, you have to compile the **game_status.proto** with *protoc*.

	$ bii open google/protobuf
	$ bii cpp:build

That will copy the binary protoc to your bin directory. Then change directory to your source folder:

	$ cd blocks/diego/soccer
	$ ../../../bin/protoc game_status.proto --cpp_out="."

Then you can close the protobuf block if you want:

	$ bii close google/protobuf

If you have any trouble with this project, please ask in http://forum.biicode.com, I will try to address issues there.
