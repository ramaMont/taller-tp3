#ifndef __SERVIDOR__
#define __SERVIDOR__

#include <map>
#include <string>
#include <mutex>

class Servidor{
private:
    std::map<std::string, std::string> recursos;
    std::mutex mtx;
public:
    explicit Servidor(std::string root);
    std::string getRecurso(std::string recurso);
    std::string postRecurso(std::string recurso, std::string body);
    std::string unknownReq(std::string recurso);
    ~Servidor();
};

#endif
