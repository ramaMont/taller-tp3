#include "ServerHolder.h"
#include <string>
#include <iostream>

ServerHolder::ServerHolder(int argc, char** argv):
    paramReaderServer(argc,argv),
    servidor(paramReaderServer.getFile()),
    svSock(paramReaderServer.getPort()){
}

void ServerHolder::run(){
    std::string c;
// aca lanzo el thread aceptador.
    while (c != "q"){
        std::cin >> c;
    }
// aca le hago join y lo mato.
    char reqst[500]="";
    Socket peer = svSock.ListenNAccept();
    peer.recive(reqst, 500);
    std::string rqstStr(reqst);
    ReqProcessor req(rqstStr);
    req.process(servidor);
}

ServerHolder::~ServerHolder(){
}
