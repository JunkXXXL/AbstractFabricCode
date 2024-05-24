#ifndef CONCRETEFACTORYCSHARP_H
#define CONCRETEFACTORYCSHARP_H

#include "factories.h"
#include "classunit.h"
#include "classcsharp.h"
#include "methodcsharp.h"
#include "printoperatorcsharp.h"

class ConcreteFactoryCSharp : public Factory
{
public:
    std::shared_ptr<ClassUnit> createClass(std::string &name) override
    {
        return std::make_shared<ClassCsharp>(ClassCsharp(name));
    }
    std::shared_ptr<MethodUnit> createMethod(std::string& name, const std::string& returnType, MethodUnit::Flags flags) override
    {
        return std::make_shared<MethodCSharp>(MethodCSharp(name, returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string& text) override
    {
        return std::make_shared<PrintOperatorCSharp>(PrintOperatorCSharp(text));
    }
};

#endif // CONCRETEFACTORYCSHARP_H
