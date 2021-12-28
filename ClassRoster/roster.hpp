#pragma once
#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include "student.hpp"
#include "degree.hpp"

class Roster {

    //TODO
    //Implement remaining Roster functions
    
public:
    Student* classRosterArray[];
    Student* parse(std::string data);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
};

#endif /* roster_hpp */
