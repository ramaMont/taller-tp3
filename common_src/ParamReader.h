#ifndef __PARAM_READER__
#define __PARAM_READER__

#include <vector>
#include <string>

class ParamReader{
private:
    std::vector<std::string> argumentos;
public:
    explicit ParamReader(int argc, char** argv);
    std::vector<std::string> getArgs();
    ~ParamReader();
};

#endif
