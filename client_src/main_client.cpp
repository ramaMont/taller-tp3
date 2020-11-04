#include <iostream>
#include "../common_src/ParamReader.h"
int main(int argc, char** argv){
    try{
        ParamReader paramReader(argc, argv);
    } catch (...){
        std::cout << "Cantidad de argumentos invalida\n";
    }
    return 0;
}