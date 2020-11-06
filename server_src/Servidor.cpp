#include "Servidor.h"
#include <fstream>
#include <utility>
#include <string>

Servidor::Servidor(std::string root){
    std::ifstream myfile(root);
    std::string contenido;
    std::string linea;
    if (!myfile.is_open()) 
        throw -1;    
    while (getline(myfile, linea))
        contenido.append(linea + '\n');
    recursos.insert(std::pair<std::string, std::string>("/",contenido));
}
std::string Servidor::getRecurso(std::string recurso){
    try {
        std::string respuesta = recursos.at(recurso);
        respuesta ="​HTTP 200 OK\nContent-Type: text/html\n\n" + respuesta;
        return respuesta;
    } catch(...){
        return "HTTP 404 NOT FOUND\n\n";
    }
}
std::string Servidor::postRecurso(std::string recurso, std::string body){
    if (recurso != "/")
        recursos.insert(std::pair<std::string, std::string>(recurso, body));
    else
        return "​HTTP 403 FORBIDDEN\n\n";
    return "";
}

Servidor::~Servidor(){
}
