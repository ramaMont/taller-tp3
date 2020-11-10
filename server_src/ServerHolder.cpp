#include "ServerHolder.h"
#include "ThAceptador.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <utility>

ServerHolder::ServerHolder(int argc, char** argv):
    paramReaderServer(argc,argv),
    servidor(paramReaderServer.getFile()){
}

void ServerHolder::run(){
    std::string close;
    ThAceptador aceptador(paramReaderServer.getPort(), servidor);
    aceptador.start();
    do{
        std::cin >> close;
    } while (close != "q");
    aceptador.stop();
    aceptador.join();
}

void ServerHolder::operator()(){
    run();
}

ServerHolder::~ServerHolder(){
}
