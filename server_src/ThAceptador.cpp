#include "ThAceptador.h"
#include "ReqProcessor.h"
#include "ThPeer.h"
#include <vector>

ThAceptador::ThAceptador(Socket &&svSockParam, Servidor &servidor):
    svSock(std::move(svSockParam)),
    servidor(servidor),
    keep_talking(true),
    is_running(true){
}

void ThAceptador::run(){
    svSock.hostListening();
    while (keep_talking){
        try{
            Socket peer = svSock.acceptClient();
            cleanForsakens();
            ThPeer *peerThread = new ThPeer(std::move(peer), servidor);
            peers.push_back(peerThread);
            peerThread->start();
        } catch(...){}
    }
    is_running = false;
}

void ThAceptador::cleanForsakens(){
    std::vector<Thread*> activeThreads;
    for (size_t i = 0; i < peers.size(); i++){
        if (peers[i]->isDone()){
            peers[i]->join();
            delete peers[i];
        } else {
            activeThreads.push_back(peers[i]);
        }
    }
    peers.swap(activeThreads);
}

bool ThAceptador::isDone(){
    return is_running;
}

void ThAceptador::stop(){
    keep_talking = false;
    for (size_t i = 0; i < peers.size(); i++){
        peers[i]->stop();
        peers[i]->join();
        delete peers[i];
    }
    svSock.shutdown();
    svSock.close();
}
