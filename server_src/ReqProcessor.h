#ifndef __REQ_PROCESSOR__
#define __REQ_PROCESSOR__

#include <string>
#include "Petitorio.h"

class ReqProcessor{
private:
    std::string request;
    Petitorio* parseReq();
public:
    explicit ReqProcessor(std::string request);
    void process();
    ~ReqProcessor();
};

#endif
