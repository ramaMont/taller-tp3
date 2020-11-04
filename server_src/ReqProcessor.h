#ifndef __REQ_PROCESSOR__
#define __REQ_PROCESSOR__

#include <string>

class ReqProcessor{
private:
    std::string request;
public:
    explicit ReqProcessor(std::string request);
    void process();
    ~ReqProcessor();
};

#endif
