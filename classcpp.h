#ifndef CLASSCPP_H
#define CLASSCPP_H

#include "classunit.h"

class ClassCpp : public ClassUnit
{
public:
    explicit ClassCpp(std::string &name): ClassUnit(name) {}
};

#endif // CLASSCPP_H
