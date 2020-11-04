#include "Petitorio.h"

// Petitorio::Petitorio(std::string recurso):recurso(recurso){
// }

Get::Get(std::string recurso):recurso(recurso){
}

Post::Post(std::string recurso, std::string body, int body_lenght):
    recurso(recurso),
    body(body),
    body_lenght(body_lenght){
}

NotAllowed::NotAllowed(){
}

std::string Get::process(){
    return "nada";
}

std::string Post::process(){
    return "nada";
}
std::string NotAllowed::process(){
    return "HTTP 403 FORBIDDEN\n\n";
}

Get::~Get(){
}

Post::~Post(){
}

NotAllowed::~NotAllowed(){
}