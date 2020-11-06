#include "ParamReader.h"
#include <string>
#include <vector>

ParamReader::ParamReader(int argc, char** argv){
    if (argc != 3) throw -1;
    std::vector<std::string> arguments(argv + 1, argv + argc);
    argumentos.swap(arguments);
}

ParamReaderServer::ParamReaderServer(int argc, char** argv):
        ParamReader(argc, argv){
}

ParamReaderClient::ParamReaderClient(int argc, char** argv):
        ParamReader(argc, argv){
}

std::string ParamReaderServer::getPort(){
    return argumentos[0];
}

std::string ParamReaderServer::getFile(){
    return argumentos[1];
}

std::string ParamReaderClient::getHost(){
    return argumentos[0];
}

std::string ParamReaderClient::getPort(){
    return argumentos[1];
}

ParamReader::~ParamReader(){
}

ParamReaderServer::~ParamReaderServer(){
}

ParamReaderClient::~ParamReaderClient(){
}
