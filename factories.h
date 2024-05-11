#ifndef FACTORIES_H
#define FACTORIES_H
#include <memory.h>

#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class Factory
{
public:
    virtual std::shared_ptr<ClassUnit> createClass(std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod() = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator() = 0;
};

#endif // FACTORIES_H
