#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H

#include "printoperatorunit.h"

class PrintOperatorJava: public PrintOperatorUnit
{
public:
    explicit PrintOperatorJava(const std::string& text) : PrintOperatorUnit(text) {}
    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "System.out.printf( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORJAVA_H
