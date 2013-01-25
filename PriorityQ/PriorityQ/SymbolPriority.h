// SymbolPriority.h - Symbol priority struct header file
// Written by: Erik Arfvidson

#pragma once

#include <iostream>

struct SymbolPriority
{

    SymbolPriority()
    {
        Symbol = NULL;
        Priority = NULL;
    }


    SymbolPriority(char symbol, int priority)
    {
        Symbol = symbol;
        Priority = priority;
    }


    bool operator < (const SymbolPriority& Important)
    {
        return this->Priority < Important.Priority;
    }


    bool operator > (const SymbolPriority& Important)
    {
        return this->Priority > Important.Priority;
    }


	bool operator <= (const SymbolPriority& Important)
    {
        return !(*this > Important);
    }


    bool operator == (const SymbolPriority& Important)
    {
        return this->Priority == Important.Priority;
    }
	    char Symbol;
    int Priority;
};

std::ostream& operator << (std::ostream& out, const SymbolPriority& symPri)
{//ALlow objects to be printed
	out << "(" << symPri.Symbol << ", " << symPri.Priority << ")" << std::endl;
    return out;
} 