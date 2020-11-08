#ifndef __PETITORIO__
#define __PETITORIO__

#include "Servidor.h"
#include <string>

class Petitorio{
public:
    virtual std::string process(Servidor &servidor) = 0;
    virtual ~Petitorio();
};

class Get final : public Petitorio{
private:
    std::string resource;
public:
    explicit Get(const std::string resource);
    virtual std::string process(Servidor &servidor) override;
    ~Get();
};

class Post final : public Petitorio{
private:
    std::string resource;
    std::string body;
public:
    explicit Post(const std::string resource, const std::string body);
    virtual std::string process(Servidor &servidor) override;
    ~Post();
};

class NotAllowed final : public Petitorio{
public:
    NotAllowed();
    virtual std::string process(Servidor &servidor) override;
    ~NotAllowed();
};

#endif
