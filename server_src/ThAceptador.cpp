#include "ThAceptador.h"
#include "ReqProcessor.h"

ThAceptador::ThAceptador(Socket &&svSockParam, Servidor &servidor):
    svSock(std::move(svSockParam)),
    servidor(servidor),
    keep_talking(true),
    is_running(true){
}

void ThAceptador::run(){
    while (keep_talking){
        char reqst[500]="";
        svSock.hostListening();
        try{
            Socket peer = svSock.acceptClient();
            peer.recive(reqst, 500);
            std::string rqstStr(reqst);
            ReqProcessor req(rqstStr);
            req.process(servidor);
        } catch(...){}

    }
    is_running = false;
}

void ThAceptador::stop(){
    keep_talking = false;
    svSock.shutdown();
    svSock.close();
}
