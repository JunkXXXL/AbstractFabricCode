#ifndef CONCRETEFACTORYJAVA_H
#define CONCRETEFACTORYJAVA_H

#include "factories.h"
#include "classjava.h"
#include "methodjava.h"
#include "printoperatorjava.h"

class ConcreteFactoryJava : public Factory
{
public:
    std::shared_ptr<ClassUnit> createClass(std::string &name) override
    {
        return std::make_shared<ClassJava>(ClassJava(name));
    }
    std::shared_ptr<MethodUnit> createMethod(std::string& name, const std::string& returnType, MethodUnit::Flags flags) override
    {
        return std::make_shared<MethodJava>(MethodJava(name, returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string& text) override
    {
        return std::make_shared<PrintOperatorJava>(PrintOperatorJava(text));
    }
};


#endif // CONCRETEFACTORYJAVA_H
