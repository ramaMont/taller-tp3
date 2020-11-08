#include "ServerHolder.h"
#include "ThAceptador.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <utility>

ServerHolder::ServerHolder(int argc, char** argv):
    paramReaderServer(argc,argv),
    servidor(paramReaderServer.getFile()),
    svSock(paramReaderServer.getPort()){
}

void ServerHolder::run(){
    std::string c;
    ThAceptador aceptador(std::move(svSock), servidor);
    aceptador.start();
    do{
        std::cin >> c;
    } while (c != "q");
    //Tiempo para que los threads se creen y aloquen memoria
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    aceptador.stop();
    aceptador.join();
}

void ServerHolder::operator()(){
    run();
}

ServerHolder::~ServerHolder(){
}
