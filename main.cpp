#include <iostream>
#include<shared_mutex>

#include "qdebug.h"

#include "classcpp.h"
#include "methodcpp.h"
#include "printoperatorcpp.h"
#include "classcsharp.h"
#include "methodcsharp.h"
#include "printoperatorcsharp.h"
#include "classjava.h"
#include "methodjava.h"
#include "printoperatorjava.h"

#include "concretefactorycpp.h"
#include "concretefactorycsharp.h"
#include "concretefactoryjava.h"

 template <typename T>
std::string generateProgram(T& factory)
{
    std::string classname("MyClass");
    std::string testFunc1("testFunc1");
    std::string testFunc2("testFunc2");
    std::string testFunc3("testFunc3");
    std::string testFunc4("testFunc4");
    std::string void_type("void");
    std::string HelloWorld("Hello, world!");

    auto myClass = factory.createClass(classname);

    auto method1 = factory.createMethod(testFunc1, void_type, 0);
    myClass->add(method1, ClassUnit::PUBLIC);
    auto method2 = factory.createMethod(testFunc2, void_type, MethodUnit::STATIC);
    myClass->add(method2, ClassUnit::PRIVATE);
    auto method3 = factory.createMethod(testFunc3, void_type, MethodUnit::VIRTUAL | MethodUnit::CONST );
    myClass->add(method3, ClassUnit::PUBLIC);
    auto method = factory.createMethod(testFunc4, void_type, MethodUnit::STATIC);
    auto print1 = factory.createPrintOperator(HelloWorld);
    method->add( print1);
    myClass->add( method, ClassCpp::PROTECTED );
    return myClass->compile();
}

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

    ClassCsharp myClass(classname);
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc1, void_type, 0 ),
        ClassCsharp::PUBLIC);
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc2, void_type, MethodCSharp::STATIC ),
        ClassCsharp::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc3, void_type, MethodCSharp::VIRTUAL | MethodCSharp::CONST ),
        ClassCsharp::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodCSharp >(testFunc5, void_type, MethodCSharp::VIRTUAL | MethodCSharp::CONST ),
        ClassCsharp::PUBLIC
        );
    auto method = std::make_shared< MethodCSharp >(testFunc4, void_type, MethodCSharp::STATIC );
    method->add( std::make_shared< PrintOperatorCSharp >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassCsharp::PROTECTED );
    return myClass.compile();
}

std::string generateProgramJava(){
    std::string classname("MyClass");
    std::string testFunc1("testFunc1");
    std::string testFunc2("testFunc2");
    std::string testFunc3("testFunc3");
    std::string testFunc4("testFunc4");
    std::string void_type("void");

    ClassJava myClass(classname);
    myClass.add(
        std::make_shared< MethodJava >(testFunc1, void_type, 0 ),
        ClassJava::PUBLIC);
    myClass.add(
        std::make_shared< MethodJava >(testFunc2, void_type, MethodJava::FINAL ),
        ClassJava::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodJava >(testFunc3, void_type, MethodJava::VIRTUAL | MethodJava::CONST ),
        ClassJava::PUBLIC
        );
    auto method = std::make_shared< MethodJava >(testFunc4, void_type, MethodJava::STATIC );
    method->add( std::make_shared< PrintOperatorJava >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassJava::PROTECTED );
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    auto fabric = ConcreteFactoryJava();
    std::string as("meme");

    //std::cout << generateProgramJava() << std::endl;
    std::cout << generateProgram(fabric);
    return 0;
}
