#include <iostream>
#include "ServerHolder.h"

int main(int argc, char** argv){
    try{
        ServerHolder serverHolder(argc, argv);
        serverHolder();
    } catch(...){
        return 1;
    }
    return 0;
}
