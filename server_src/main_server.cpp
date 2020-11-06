#include <iostream>
#include "../common_src/ParamReader.h"
#include "ReqProcessor.h"
#include "Servidor.h"
#include "../common_src/Socket.h"
#include <string>

std::string request = 
"GET /sd HTTP/1.1\nUser-Agent: Wget/1.20.3 (linux-gnu)\nAccept: */*\nAccept-Encoding: identity\nHost: localhost:8088\nConnection: Keep-Alive\n";
//"POST / HTTP/1.1\nUser-Agent: Wget/1.20.3 (linux-gnu)\nAccept: */*\nAccept-Encoding: identity\nHost: localhost:8088\nContent-Length: 90\nConnection: Keep-Alive\n\n<!DOCTYPE html>\n<html>\n	<head></head>\n	<body>\n		<h1>Mi recurso test</h1>\n	</body>\n</html>";
//"PUT / HTTP/1.1\nUser-Agent: Wget/1.20.3 (linux-gnu)\nAccept: */*\nAccept-Encoding: identity";

int main(int argc, char** argv){
    try{
        char reqst[500]="";
        ParamReaderServer paramReaderServer(argc, argv);
        Servidor servidor(paramReaderServer.getFile());
        ServerSocket svSock("7777");
        Socket peer = svSock.ListenNAccept();
        peer.recive(reqst, 500);
        std::string rqstStr(reqst);
        ReqProcessor req(rqstStr);
        req.process(servidor);
    } catch (...){
        std::cout << "Cantidad de argumentos invalida\n";
        return 1;
    }

    return 0;
}