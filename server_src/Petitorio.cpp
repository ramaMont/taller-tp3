#include "Petitorio.h"
#include <string>

Get::Get(const std::string& resource): resource(resource){
}

Post::Post(const std::string& resource, const std::string& body):
    resource(resource),
    body(body){
}

NotAllowed::NotAllowed(){
}

std::string Get::process(Servidor &servidor){
    return servidor.getRecurso(resource);
}

std::string Post::process(Servidor &servidor){
    return servidor.postRecurso(resource, body);;
}
std::string NotAllowed::process(Servidor &servidor){
    return "HTTP 405 METHOD NOT ALLOWED\n\n";
}

Get::~Get(){
}

Post::~Post(){
}

NotAllowed::~NotAllowed(){
}

Petitorio::~Petitorio(){
}
