#pragma once
#ifndef degree_hpp
#define degree_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Degree
{
public:
    //Enum of available degree programs with a parallel string array for printing use
    enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, NONE};
    static inline const std::string sDegreeProgram[4] = {"Security", "Network", "Software", "None"};
};

#endif /* degree_hpp */
