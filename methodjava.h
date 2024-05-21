#ifndef METHODJAVA_H
#define METHODJAVA_H

#include "methodunit.h"

class MethodJava: public MethodUnit
{
public:
    explicit MethodJava(std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags)
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
        } else if( m_flags & CONST ) {
            result += "const ";
        }

        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }

};

#endif // METHODJAVA_H
