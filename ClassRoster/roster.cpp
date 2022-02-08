#include "roster.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

//Add takes parsed input, manipulates data as needed, and adds a new student
//      to the roster array
void Roster::add(std::string studentID, std::string firstName,
                 std::string lastName, std::string emailAddress,
                 int age, int daysInCourse1, int daysInCourse2,
                 int daysInCourse3, Degree::DegreeProgram degreeProgram) {
    //Consolidate days remaining in courses into a single array
    int daysInCourses[Student::courseNum] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //Push a new student with parsed arguments to classRosterArray
    classRosterArray.back()->setStudentID(studentID);
    classRosterArray.back()->setFirstName(firstName);
    classRosterArray.back()->setLastName(lastName);
    classRosterArray.back()->setEmailAddress(emailAddress);
    classRosterArray.back()->setAge(age);
    classRosterArray.back()->setDegreeProgram(degreeProgram);
    
    for(int i = 0; i < Student::courseNum; i++) {
        classRosterArray.back()->setDaysInCourses(i, daysInCourses[i]);
    }
}

//Removes a student by their ID
void Roster::removeByID(std::string studentID) {
    //Loops through the Roster to find the given ID
    for (int i = 0; i < classRosterArray.size(); i++) {
        //If the ID is found, print out which ID is to be removed
        if (classRosterArray[i]->getStudentID() == studentID) {
            std::cout << classRosterArray[i]->getStudentID() << " was removed from the roster." << std::endl;
            //Sends the student to be deleted to the end of the array then pops the array,
            //      bringing the student out of scope and freeing it from memory
            auto iter = classRosterArray.begin() + i;
            std::rotate(iter, iter + 1, classRosterArray.end());
            classRosterArray.pop_back();
            break;
        }
        //If ID is not found, return an ERROR message
        else if (i == classRosterArray.size()-1) {
            std::cout << "Error: " << studentID << " not found." << std::endl;
        }
    }
}

//Prints the average days of all three courses within the daysInCourses array
void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < classRosterArray.size(); i++) {
        //Checks for an ID match
        if (classRosterArray[i]->getStudentID() == studentID) {
            //Calculates and then prints the average days of all courses
            int average = classRosterArray[i]->getDaysInCourses()[0] +                                        classRosterArray[i]->getDaysInCourses()[1] +                                        classRosterArray[i]->getDaysInCourses()[2];
            average /= 3;
            std:: cout << "Average days remaining in courses: " << average << std::endl;
            break;
        }
    }
}

//Loops through the entire roster and calls the student->print function
void Roster::printAll() {
    for (int i = 0; i < classRosterArray.size(); i++) {
        classRosterArray[i]->print();
    }
}

//Loops through the entire roster to check for and print invalid emails
void Roster::printInvalidEmails() {
    //Init a check variable
    std::string emailCheck = "";
    //Loops through the roster to check for emails
    for (int i = 0; i < classRosterArray.size(); i++) {
        //The check variable is assigned the currently indexed student object
        emailCheck = classRosterArray[i]->getEmailAddress();
        //If find returns an npos, this means the character is absent and the
        //      email is printed or skipped accordingly
        
        const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        
        if (!std::regex_match(emailCheck, pattern)) {
            std::cout << emailCheck << std::endl;
        }
        /*if (emailCheck.find("@") == std::string::npos) {
            std::cout << emailCheck << std::endl;
        }
        else if (emailCheck.find(".") == std::string::npos) {
            std::cout << emailCheck << std::endl;
        }
        else if (!(emailCheck.find(" ") == std::string::npos)) {
            std::cout << emailCheck << std::endl;
        }*/
    }
}

//Loops through the entire roster to check for and print out by degree program
void Roster::printByDegreeProgram(Degree::DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray.size(); i++) {
        //The check variable is assigned the currently indexed student object
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

//Parse takes student data input via an array of strings and separates out
//      data to their respective variables for assignment
void Roster::parse(std::string data) {
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
    Degree::DegreeProgram dp;
    
    if (sDegreeProgram == "SECURITY") { dp = Degree::DegreeProgram::SECURITY; }
    if (sDegreeProgram == "NETWORK") { dp = Degree::DegreeProgram::NETWORK; }
    if (sDegreeProgram == "SOFTWARE") { dp = Degree::DegreeProgram::SOFTWARE; }
    
    //Calls the add function, sending all parsed data for student object instantiation
    classRosterArray.push_back(new Student);
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
}
