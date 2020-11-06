#include <iostream>
#include "../common_src/ParamReader.h"
#include "ReqProcessor.h"
#include "Servidor.h"
#include "../common_src/Socket.h"
#include <string>

int main(int argc, char** argv){
    try{
        char reqst[500]="";
        ParamReaderServer paramReaderServer(argc, argv);
        Servidor servidor(paramReaderServer.getFile());
        ServerSocket svSock(paramReaderServer.getPort());
        Socket peer = svSock.ListenNAccept();
        peer.recive(reqst, 500);
        std::string rqstStr(reqst);
        ReqProcessor req(rqstStr);
        req.process(servidor);
    } catch(...){
        std::cout << "Cantidad de argumentos invalida\n";
        return 1;
    }
    return 0;
}
