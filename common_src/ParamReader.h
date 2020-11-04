#ifndef __PARAM_READER__
#define __PARAM_READER__

#include <vector>
#include <string>

class ParamReader{
protected:
    std::vector<std::string> argumentos;
public:
    explicit ParamReader(int argc, char** argv);
    virtual std::string getPort() = 0;
    ~ParamReader();
};

class ParamReaderServer : public ParamReader{
public:
    explicit ParamReaderServer(int argc, char** argv);
    virtual std::string getPort() override;
    std::string getFile();
    ~ParamReaderServer();
};

class ParamReaderClient : public ParamReader{
public:
    explicit ParamReaderClient(int argc, char** argv);
    virtual std::string getPort() override;
    std::string getHost();
    ~ParamReaderClient();
};

#endif
