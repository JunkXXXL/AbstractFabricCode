#ifndef METHODCPP_H
#define METHODCPP_H

#include "methodunit.h"

class MethodCpp: public MethodUnit
{
public:
    explicit MethodCpp(std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags)
    {}

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 2 );
        }
        result += generateShift( level + 1 ) + "}\n";
        return result;
    }

};

#endif // METHODCPP_H
