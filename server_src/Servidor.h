#ifndef __SERVIDOR__
#define __SERVIDOR__

#include <map>
#include <string>

class Servidor{
private:
    std::map<std::string, std::string> recursos;
public:
    explicit Servidor(std::string root);
    std::string getRecurso(std::string recurso);
    std::string postRecurso(std::string recurso, std::string body);
    ~Servidor();
};

#endif
