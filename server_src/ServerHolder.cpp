#include "ServerHolder.h"
#include "ThAceptador.h"
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
    ThAceptador aceptador(std::move(svSock), servidor);
    aceptador.start();
    do{
        std::cin >> c;
    } while (c != "q");
    aceptador.stop();
// aca le hago join y lo mato.
    aceptador.join();
}

void ServerHolder::operator()(){
    run();
}

ServerHolder::~ServerHolder(){
}
