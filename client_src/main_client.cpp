#include <iostream>
#include "ClientHolder.h"
int main(int argc, char** argv){
    try{
        ClientHolder clientHolder(argc, argv);
        clientHolder();
    } catch(...){}
    return 0;
}
