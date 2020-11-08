#include "Petitorio.h"
#include <string>

Get::Get(const std::string& resource): resource(resource){
}

Post::Post(const std::string& resource, const std::string& body):
    resource(resource),
    body(body){
}

NotAllowed::NotAllowed(const std::string& method_name):method_name(method_name){
}

std::string Get::process(Servidor &servidor){
    return servidor.getRecurso(resource);
}

std::string Post::process(Servidor &servidor){
    return servidor.postRecurso(resource, body);;
}
std::string NotAllowed::process(Servidor &servidor){
    return servidor.unknownReq(method_name);
}

Get::~Get(){
}

Post::~Post(){
}

NotAllowed::~NotAllowed(){
}

Petitorio::~Petitorio(){
}
