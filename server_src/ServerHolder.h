#ifndef __SERVER_HOLDER__
#define __SERVER_HOLDER__

#include "../common_src/Socket.h"
#include "../common_src/ParamReader.h"
#include "ReqProcessor.h"
#include "Servidor.h"

class ServerHolder{
private:
    ParamReaderServer paramReaderServer;
    Servidor servidor;
    ServerSocket svSock;
public:
    explicit ServerHolder(int argc, char** argv);
    void run();
    ~ServerHolder();
};

#endif