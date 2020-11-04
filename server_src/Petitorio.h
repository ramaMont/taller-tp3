#ifndef __PETITORIO__
#define __PETITORIO__

#include <string>

class Petitorio{
    virtual std::string process() = 0;
};

class Get : public Petitorio{
private:
    std::string recurso;
public:
    explicit Get(std::string recurso);
    virtual std::string process() override;
    ~Get();
};

class Post : public Petitorio{
private:
    std::string recurso;
    std::string body;
    int body_lenght;
public:
    explicit Post(std::string recurso, std::string body, int body_lenght);
    virtual std::string process() override;
    ~Post();
};

class NotAllowed : public Petitorio{
public:
    NotAllowed();
    virtual std::string process() override;
    ~NotAllowed();
};

#endif
