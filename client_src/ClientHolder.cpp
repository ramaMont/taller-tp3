#include "ClientHolder.h"

#include <iostream>
#include <sstream>

#define MAX_RECIVED 1000

void ClientHolder::run(){
    std::string input;
    std::string line;
    std::string recibido;
    while (getline(std::cin, line))
        input.append(line+"\n");
    cliSkt.sendStr(input, input.length());
    cliSkt.recive(recibido, MAX_RECIVED);
    std::cout << recibido;
}

ClientHolder::ClientHolder(int argc, char** argv):
    paramReaderClient(argc, argv),
    cliSkt(paramReaderClient.getHost(), paramReaderClient.getPort()){
}
void ClientHolder::operator ()(){
    run();
}
ClientHolder::~ClientHolder(){
}
