#include <iostream>
#include<shared_mutex>

#include "classcpp.h"
#include "methodcpp.h"
#include "printoperatorcpp.h"
#include "classcsharp.h"
#include "methodcsharp.h"
#include "printoperatorcsharp.h"

std::string generateProgramC() {
    std::string classname("MyClass");
    std::string testFunc1("testFunc1");
    std::string testFunc2("testFunc2");
    std::string testFunc3("testFunc3");
    std::string testFunc4("testFunc4");
    std::string void_type("void");

    ClassCpp myClass(classname);
    myClass.add(
        std::make_shared< MethodCpp >(testFunc1, void_type, 0 ),
        ClassCpp::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodCpp >(testFunc2, void_type, MethodCpp::STATIC ),
        ClassCpp::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodCpp >(testFunc3, void_type, MethodCpp::VIRTUAL | MethodCpp::CONST ),
        ClassCpp::PUBLIC
        );
    auto method = std::make_shared< MethodCpp >(testFunc4, void_type, MethodCpp::STATIC );
    method->add( std::make_shared< PrintOperatorCpp >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassCpp::PROTECTED );
    return myClass.compile();
}

std::string generateProgramCSharp() {
    std::string classname("MyClass");
    std::string testFunc1("testFunc1");
    std::string testFunc2("testFunc2");
    std::string testFunc3("testFunc3");
    std::string testFunc4("testFunc4");
    std::string testFunc5("testFunc5");
    std::string void_type("void");

    ClassCsharp myClass(classname, ClassUnit::PUBLIC);
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc1, void_type, 0 ),
        ClassCsharp::PUBLIC);
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc2, void_type, MethodCSharp::STATIC ),
        ClassCsharp::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodCpp >(testFunc3, void_type, MethodCSharp::VIRTUAL | MethodCSharp::CONST ),
        ClassCsharp::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodCpp >(testFunc5, void_type, MethodCSharp::VIRTUAL | MethodCSharp::CONST ),
        ClassCsharp::PUBLIC
        );
    auto method = std::make_shared< MethodCSharp >(testFunc4, void_type, MethodCSharp::STATIC );
    method->add( std::make_shared< PrintOperatorCSharp >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassCsharp::PROTECTED );
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    std::cout << generateProgramCSharp() << std::endl;
    return 0;
}
