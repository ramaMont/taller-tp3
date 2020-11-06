#ifndef __SOCKET__
#define __SOCKET__

#include <string>

class Socket{
protected:
    int socketFd;
public:
    Socket();
    Socket(int socketFd);
    int sendStr(const char* msg, size_t size);
    int recive(char *buff, size_t size);
    Socket(const Socket&) = delete;
    Socket(Socket&& other);
    Socket& operator=(const Socket&) = delete;
    Socket& operator=(Socket&& other);
    ~Socket();
};

class ServerSocket : public Socket{
private:
    void hostNBind(struct addrinfo *pr);
    void reUseHost(struct addrinfo *pr);
    void bindHost(struct addrinfo *pr);
    void hostListening();
    Socket acceptClient();
public:
    explicit ServerSocket(std::string port);
    Socket ListenNAccept();
    ~ServerSocket();
};

class ClientSocket : public Socket{
public:
    ClientSocket();
    void connect();
    ~ClientSocket();
};

#endif
