#pragma once
#ifndef degree_hpp
#define degree_hpp

#include <stdio.h>
#include <vector>
#include <string>

class degree
{
public:
    enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};
    static inline const std::string sDegreeProgram[3] = {"SECURITY", "NETWORK", "SOFTWARE"};
};

#endif /* degree_hpp */
