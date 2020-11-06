#include "ServerHolder.h"
#include <string>

ServerHolder::ServerHolder(int argc, char** argv):
    paramReaderServer(argc,argv),
    servidor(paramReaderServer.getFile()),
    svSock(paramReaderServer.getPort()){
}

void ServerHolder::run(){
    char reqst[500]="";
    Socket peer = svSock.ListenNAccept();
    peer.recive(reqst, 500);
    std::string rqstStr(reqst);
    ReqProcessor req(rqstStr);
    req.process(servidor);
}

ServerHolder::~ServerHolder(){
}
