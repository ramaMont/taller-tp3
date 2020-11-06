#ifndef __TH_PEER__
#define __TH_PEER__

#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "Servidor.h"
#include <atomic>

class ThPeer final : public Thread{
private:
    Socket peerSock;
    Servidor &servidor;
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
public:
    explicit ThPeer(Socket &&peerSock, Servidor &servidor);
    virtual void run() override;
    virtual void stop() override;
    virtual bool isDone() override;
};

#endif
