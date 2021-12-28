#pragma once
#ifndef student_hpp
#define student_hpp

#include <string>
#include <experimental/iterator>
#include <vector>
#include "degree.hpp"

class Student {
    //Student Attributes
    std::string studentID = "";
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress = "";
    int age = 0;
    std::vector<int> daysInCourse;
    degree::DegreeProgram degreeProgram;

public:
    //Student constructors, both default and parameterized
    Student();
    Student(std::string _studentID, std::string _firstName, std::string _lastName, std::string _emailAddress, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::DegreeProgram _degreeProgram)
    :
        studentID(_studentID),
        firstName(_firstName),
        lastName(_lastName),
        emailAddress(_emailAddress),
        age(_age),
        degreeProgram(_degreeProgram)
    {
        daysInCourse.push_back(daysInCourse1);
        daysInCourse.push_back(daysInCourse2);
        daysInCourse.push_back(daysInCourse3);
    };
    
    void print();
    
    //Getters and Setters for member variables
    std::string getStudentID();
    void setStudentID(int ageToSet);
    
    std::string getFirstName();
    void setFirstName(std::string firstNameToSet);
    
    std::string getLastName();
    void setLastName(std::string lastNameToSet);
    
    std::string getEmailAddress();
    void setEmailAddress(std::string emailAddressToSet);
    
    int getAge();
    void setAge(int ageToSet);
    
    std::vector<int> getDaysInCourse();
    void setDaysInCourse(int course, int daysInCourseToSet);
    
    degree::DegreeProgram getDegreeProgram();
    void setDegreeProgram(degree::DegreeProgram degreeProgramToSet);
    
    /*//Functions for printing/verifying specific student data
    void printStudentData(Student student);
    void printAverageDays(std::vector<int> daysInCourse);
    void verifyEmailAddress(std::string emailAddress);
    */
};
#endif /* student_hpp */
