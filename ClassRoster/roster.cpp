#include "roster.hpp"

//Parse takes student data input via an array of strings and separates out
//      data to their respective variables for assignment
Student* parse(std::string data) {
    //Finds a "," character and uses that to find substring endings
    
    //StudentID
    size_t rhs = data.find(",");
    std::string studentID = data.substr(0, rhs);
    
    //First Name
    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string firstName = data.substr(lhs, rhs - lhs);
    
    //Last Name
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string lastName = data.substr(lhs, rhs - lhs);
    
    //Email Address
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string emailAddress = data.substr(lhs, rhs - lhs);
    
    //Age | Converts from string input to int
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string sAge = data.substr(lhs, rhs - lhs);
    int age = stoi(sAge);
    
    //Days in course remaining: 1 - 3 | Converts from string input to int
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string sDaysInCourse1 = data.substr(lhs, rhs - lhs);
    int daysInCourse1 = stoi(sDaysInCourse1);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string sDaysInCourse2 = data.substr(lhs, rhs - lhs);
    int daysInCourse2 = stoi(sDaysInCourse2);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string sDaysInCourse3 = data.substr(lhs, rhs - lhs);
    int daysInCourse3 = stoi(sDaysInCourse3);
    
    //Degree Program | Converts from string input to enum on context
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    std::string sDegreeProgram = data.substr(lhs, rhs - lhs);
    degree::DegreeProgram dp;
    
    if (sDegreeProgram == "SECURITY") { dp = degree::DegreeProgram::SECURITY; }
    if (sDegreeProgram == "NETWORK") { dp = degree::DegreeProgram::NETWORK; }
    if (sDegreeProgram == "SOFTWARE") { dp = degree::DegreeProgram::SOFTWARE; }
    
    //Instantiates a new Student object
    return new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
}
