#include "ReqProcessor.h"
#include <iostream>
#include <sstream>


ReqProcessor::ReqProcessor(std::string request):request(request){
}

void ReqProcessor::process(){
    Petitorio *petitorio = parseReq();
    std::string result = petitorio->process();
    std::cout << result << std::endl;
    delete petitorio;
}

void parseMethod(std::string &method, std::string &resource, const std::string &line, bool &done){
    std::stringstream s_stream(line);
    std::string word;
    int pos = 0;
    while (s_stream >> word){
        if (pos == 0)
            method.swap(word);
        if (pos == 1)
            resource.swap(word);
        ++pos;
    }
    if (method != "POST")
        done = true;
}

Petitorio* reqCreator(std::string& method_name,
        std::string& resource, std::string& body){
    if (method_name == "GET")
        return new Get(resource);
    if (method_name == "POST")
        return new Post(resource, body);
    return new NotAllowed();
}

Petitorio* ReqProcessor::parseReq(){
    int line_number = 0;
    std::stringstream s_stream(request);
    std::string line;
    std::string method_name;
    std::string resource;
    std::string body;
    bool done = false;
    bool hayBody = false;

    while (std::getline(s_stream, line, '\n') and !done){
        if (line_number == 0)
            parseMethod(method_name, resource, line, done);
        if (hayBody)
            body.append(line+'\n');
        if (line == "")
            hayBody = true;
        ++line_number;
    }

    return reqCreator(method_name, resource, body);
}

ReqProcessor::~ReqProcessor(){
}