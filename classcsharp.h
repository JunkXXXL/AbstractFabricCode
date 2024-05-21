#ifndef CLASSCSHARP_H
#define CLASSCSHARP_H
#include "classunit.h"

class ClassCsharp: public ClassUnit
{
public:
    explicit ClassCsharp(std::string &name, AccessModifier modifier): ClassUnit(name) { Currentmodifier = modifier;}
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override
    {
        int accessModifier;
        if (flags == PROTECTED) {
            accessModifier = PROTECTED;
        } else if (flags == PUBLIC) {
            accessModifier = PUBLIC;
        } else if (flags == PRIVATE) {
            accessModifier = PRIVATE;
        } else if (flags == PRIVATE_PROTECTED){
            accessModifier = PRIVATE_PROTECTED;
        } else if (flags == INTERNAL) {
            accessModifier = INTERNAL;
        } else if (flags == PROTECTED_INTERNAL) {
            accessModifier = PROTECTED_INTERNAL;
        }
        else return;
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile(unsigned int level = 0) const override
    {
        std::string result = generateShift( level ) + ACCESS_MODIFIERS[int(Currentmodifier)] + " class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            if( m_fields[ i ].empty() ) {
                continue;
            }

            for( const auto& f : m_fields[ i ] )
            {
                result += ACCESS_MODIFIERS[ i ] + f->compile( level + 1 );
            }

            result += "\n";
        }

        result += generateShift( level ) + "};\n";
        return result;
    }

private:
    AccessModifier Currentmodifier;

};

#endif // CLASSCSHARP_H
