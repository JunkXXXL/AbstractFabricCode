#ifndef PRINTOPERATORCSHARP_H
#define PRINTOPERATORCSHARP_H

#include "printoperatorunit.h"

class PrintOperatorCSharp: public PrintOperatorUnit
{
public:
    explicit PrintOperatorCSharp(const std::string& text) : PrintOperatorUnit(text) {}
    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORCSHARP_H
