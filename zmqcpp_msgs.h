#pragma once

#include <string>
#include "diego/zmqcpp/zmq.hpp"

inline std::string get_str(const zmq::message_t& msg){
    return std::string((char*) msg.data(), msg.size());
}

inline void get_msg(const std::string& str, zmq::message_t& msg){
    msg.rebuild(str.length());
    memcpy ((void *) msg.data (), str.c_str(), str.length());
}


