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
    virtual std::shared_ptr<MethodUnit> createMethod(std::string& name, const std::string& returnType, MethodUnit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string& text) = 0;
};

#endif // FACTORIES_H
