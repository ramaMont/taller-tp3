#include <iostream>
#include "../common_src/ParamReader.h"
int main(int argc, char** argv){
    try{
        ParamReaderClient paramReaderClient(argc, argv);
    } catch (...){
        std::cout << "Cantidad de argumentos invalida\n";
    }
    return 0;
}