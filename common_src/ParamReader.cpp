#include "ParamReader.h"

ParamReader::ParamReader(int argc, char** argv){
    if (argc != 3) throw -1;
    std::vector<std::string> arguments(argv + 1, argv + argc);
    argumentos.swap(arguments);
}

std::vector<std::string> ParamReader::getArgs(){
    return argumentos;
}

ParamReader::~ParamReader(){
}
