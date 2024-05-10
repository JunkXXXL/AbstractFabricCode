#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <vector>

class Class
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    explicit Class(std::string &name) : _name(name) {};

protected:
    std::string _name;
};

#endif // CLASS_H
