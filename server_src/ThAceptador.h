#ifndef __TH_ACEPTADOR__
#define __TH_ACEPTADOR__

#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "Servidor.h"
#include <atomic>
#include <vector>

class ThAceptador final : public Thread{
private:
    std::vector<Thread*> peers;
    Socket svSock;
    Servidor &servidor;
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
public:
    explicit ThAceptador(Socket &&svSockParam, Servidor &servidor);
    virtual void run() override;
    void stop();
};

#endif
