#ifndef CLASSCPP_H
#define CLASSCPP_H

#include "classunit.h"

class ClassCpp : public ClassUnit
{
public:
    explicit ClassCpp(std::string &name): ClassUnit(name) {}
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override
    {
        int accessModifier = PRIVATE;   // по умолчанию private
        if (flags == PROTECTED) {
            accessModifier = PROTECTED;
        } else if (flags == PUBLIC) {
            accessModifier = PUBLIC;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile(unsigned int level = 0) const override
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";   // делаем отступ и выводим инициализацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            if( m_fields[ i ].empty() ) {
                continue;   // Пропускаем вывод модификатора доступа, если не было добавлено.
                    // ни одной члена-данных/члена-функции с соотвествующим модификатором доступа.
            }

            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[ i ] )    // проход по каждому модификатору доступа
            {
                result += f->compile( level + 1 );  // добавляем в result текст член-функции/член-данные c соответствуюзщим отступом
            }

            result += "\n";
        }

        result += generateShift( level ) + "};\n";
        return result;
    }
};

#endif // CLASSCPP_H
