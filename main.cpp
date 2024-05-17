#include <iostream>
#include "classcpp.h"
#include "methodcpp.h"
#include "printoperatorcpp.h"
#include<shared_mutex>

std::string generateProgram() {
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

int main(int argc, char *argv[])
{
    std::cout << generateProgram() << std::endl;
    return 0;
}
