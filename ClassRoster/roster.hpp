#pragma once
#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include <vector>
#include "student.hpp"
#include "degree.hpp"
#include <functional>

class Roster {
public:
    //Destructor for dynamically created student objects
    ~Roster() {
        for (int i = 0; i < classRosterArray.size(); i++) {
            std::cout << classRosterArray[i]->getStudentID() << " ";
            delete classRosterArray[i];
            //Points away from the now freed memory to avoid a crash
            classRosterArray[i] = nullptr;
        }
        classRosterArray.clear();
    }
    
    //Definition of the roster array and the three functions to mutate it
    std::vector<Student*> classRosterArray;
    void parse(std::string data);
    void add(std::string studentID,
             std::string firstName,
             std::string lastName,
             std::string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             Degree::DegreeProgram degreeProgram);
    void removeByID(std::string studentID);
    
    //Definition of all print functions for the roster
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree::DegreeProgram degreeProgram);
};

#endif /* roster_hpp */
