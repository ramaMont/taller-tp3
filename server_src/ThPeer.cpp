#include "ThPeer.h"
#include "ReqProcessor.h"

#include <string>
#include <iostream>
#include <utility>

#define MAX_RECIVED 1000

ThPeer::ThPeer(Socket &&peerSock, Servidor &servidor):
    peerSock(std::move(peerSock)),
    servidor(servidor),
    keep_talking(true),
    is_running(true){
}

void ThPeer::run(){
    try{
        std::string request;
        std::string response;
        peerSock.recive(request, MAX_RECIVED);
        ReqProcessor req(request);
        response = req.process(servidor);
        peerSock.sendStr(response, response.length());
    } catch(...){}
    is_running = false;
}

bool ThPeer::isDone(){
    return is_running;
}

void ThPeer::stop(){
    is_running = false;
    peerSock.shutdown();
    peerSock.close();
}
