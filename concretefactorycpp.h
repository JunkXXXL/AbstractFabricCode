#ifndef CONCRETEFACTORYCPP_H
#define CONCRETEFACTORYCPP_H

#include "factories.h"
#include "classcpp.h"
#include "methodcpp.h"
#include "printoperatorcpp.h"
#include "QDebug"

class ConcreteFactoryCpp : public Factory
{
public:
    std::shared_ptr<ClassUnit> createClass(std::string &name) override
    {
        return std::make_shared<ClassCpp>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(std::string& name, const std::string& returnType, MethodUnit::Flags flags) override
    {
        return std::make_shared<MethodCpp>(MethodCpp(name, returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string& text) override
    {
        return std::make_shared<PrintOperatorCpp>(PrintOperatorCpp(text));
    }
};

#endif // CONCRETEFACTORYCPP_H
