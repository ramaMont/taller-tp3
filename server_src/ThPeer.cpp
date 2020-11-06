#include "ThPeer.h"
#include "ReqProcessor.h"

ThPeer::ThPeer(Socket &&peerSock, Servidor &servidor):
    peerSock(std::move(peerSock)),
    servidor(servidor),
    keep_talking(true),
    is_running(true){

}

void ThPeer::run(){
    char reqst[500]="";
    try{
        peerSock.recive(reqst, 500);
        std::string rqstStr(reqst);
        ReqProcessor req(rqstStr);
        req.process(servidor);
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
