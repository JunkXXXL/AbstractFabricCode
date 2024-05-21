#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include "classunit.h"

class ClassJava: public ClassUnit
{
public:
    explicit ClassJava(std::string &name, AccessModifier modifier): ClassUnit(name) { Currentmodifier = modifier;}
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override
    {
        int accessModifier;
        if (flags == PROTECTED) {
            accessModifier = PROTECTED;
        } else if (flags == PUBLIC) {
            accessModifier = PUBLIC;
        } else if (flags == PRIVATE) {
            accessModifier = PRIVATE;
        }  else return;
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
                result += generateShift(level + 1) + ACCESS_MODIFIERS[ i ] + f->compile( level + 1 );
            }

            result += "\n";
        }

        result += generateShift( level ) + "};\n";
        return result;
    }

private:
    AccessModifier Currentmodifier;

};

#endif // CLASSJAVA_H
