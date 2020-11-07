#ifndef __CLIENT_HOLDER__
#define __CLIENT_HOLDER__

#include "../common_src/ParamReader.h"
#include "../common_src/Socket.h"

class ClientHolder{
private:
    ParamReaderClient paramReaderClient;
    Socket cliSkt;
    void run();
public:
    explicit ClientHolder(int argc, char** argv);
    void operator ()();
    ~ClientHolder();
};

#endif
