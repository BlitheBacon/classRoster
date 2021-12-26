#include "student.hpp"
#include <iostream>

std::string Student::getStudentID()
{
    return studentID;
}

void Student::setStudentID(int studentIDToSet)
{
    studentID = studentIDToSet;
}

std::string Student::getFirstName()
{
    return firstName;
}

void Student::setFirstName(std::string firstNameToSet)
{
    firstName = firstNameToSet;
}

std::string Student::getLastName()
{
    return lastName;
}

void Student::setLastName(std::string lastNameToSet)
{
    lastName = lastNameToSet;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

void Student::setEmailAddress(std::string emailAddressToSet)
{
    emailAddress = emailAddressToSet;
}

int Student::getAge()
{
    return age;
}

void Student::setAge(int ageToSet)
{
    age = ageToSet;
}

std::vector<int> Student::getDaysInCourse()
{
    return daysInCourse;
}

void Student::setDaysInCourse(int course, int daysInCourseToSet)
{
    daysInCourse.at(course) = daysInCourseToSet;
}

degree::DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

void Student::setDegreeProgram(degree::DegreeProgram degreeProgramToSet)
{
    degreeProgram = degreeProgramToSet;
    std::cout << this->degreeProgram << std::endl;
}
