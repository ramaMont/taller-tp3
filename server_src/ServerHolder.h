#ifndef __SERVER_HOLDER__
#define __SERVER_HOLDER__

#include "../common_src/Socket.h"
#include "../common_src/ParamReader.h"
#include "Servidor.h"

class ServerHolder{
private:
    ParamReaderServer paramReaderServer;
    Servidor servidor;
    Socket svSock;
    void run();
public:
    explicit ServerHolder(int argc, char** argv);
    void operator()();
    ~ServerHolder();
};

#endif
