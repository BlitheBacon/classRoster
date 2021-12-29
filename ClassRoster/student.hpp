#pragma once
#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <string>
#include <experimental/iterator>
#include <vector>
#include "degree.hpp"

class Student {
    //Class Constants
public:
    static constexpr int courseNum = 3;

private:
    //Student Attributes
    std::string studentID = "";
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress = "";
    int age = 0;
    int daysInCourses[courseNum];
    Degree::DegreeProgram degreeProgram;
    
public:
    //Student constructors and destructors, both default and parameterized
    Student()
    {
        this->studentID = "";
        this->firstName = "";
        this->lastName = "";
        this->emailAddress = "";
        this->age = 0;
        this->degreeProgram = Degree::NONE;
        //Loops through the member array to zero out the array
        for (int i = 0; i < courseNum; i++) {daysInCourses[i] = 0;}
    };
    Student(std::string _studentID,
            std::string _firstName,
            std::string _lastName,
            std::string _emailAddress,
            int _age,
            int _daysInCourses[],
            Degree::DegreeProgram _degreeProgram)
    :
        studentID(_studentID),
        firstName(_firstName),
        lastName(_lastName),
        emailAddress(_emailAddress),
        age(_age),
        degreeProgram(_degreeProgram)
    {
        for (int i = 0; i < courseNum; i++) {
            daysInCourses[i] = _daysInCourses[i];
        }
    };
    //Will be called right after the destructor from Roster for verification of destructor call
    ~Student()
    {std::cout << "Destroyed\n";}
    
    //Full data print for students, used by Roster's printAll function
    void print();
    
    //Getters and Setters for member variables
    //studentID
    const std::string getStudentID() const;
    void setStudentID(std::string studentIDToSet);
    
    //FirstName
    const std::string getFirstName() const;
    void setFirstName(std::string firstNameToSet);
    
    //LastName
    const std::string getLastName() const;
    void setLastName(std::string lastNameToSet);
    
    //EmailAddress
    const std::string getEmailAddress() const;
    void setEmailAddress(std::string emailAddressToSet);
    
    //Age
    const int getAge() const;
    void setAge(int ageToSet);
    
    //DaysInCourses
    const int* getDaysInCourses() const;
    void setDaysInCourses(int course, int daysInCourseToSet);
    
    //DegreeProgram
    const Degree::DegreeProgram getDegreeProgram() const;
    void setDegreeProgram(Degree::DegreeProgram degreeProgramToSet);
};
#endif /* student_hpp */
