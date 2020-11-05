#include "Petitorio.h"

Get::Get(std::string resource): resource(resource){
}

Post::Post(std::string resource, std::string body):
    resource(resource),
    body(body){
}

NotAllowed::NotAllowed(){
}

std::string Get::process(){
    return "GET-TODO";
}

std::string Post::process(){
    return "POST-TODO";
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

Petitorio::~Petitorio(){
}
