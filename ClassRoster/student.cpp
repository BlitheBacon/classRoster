#include "student.hpp"
#include "degree.hpp"
#include <iostream>

//Prints all student data with tabbed formatting
void Student::print() {
    std::cout << this->getStudentID() << "\t"
              << "First Name: " << this->getFirstName() << "\t"
              << "Last Name: " << this->getLastName() << "\t\t"
              << "Age: " << this->getAge() << "\t\t"
              << "Days in Courses: { " << this->getDaysInCourses()[0] << ", "
              << this->getDaysInCourses()[1] << ", "
              << this->getDaysInCourses()[2] << " } \t"
              << "Degree Program: " << Degree::sDegreeProgram[this->getDegreeProgram()] << "\t"
    << std::endl;
}

//Getters (Accessors) and Setters (Mutators) for Student data
//studentID
const std::string Student::getStudentID() const { return this->studentID; }
void Student::setStudentID(std::string studentIDToSet) { this->studentID = studentIDToSet; }

//FirstName
const std::string Student::getFirstName() const { return this->firstName; }
void Student::setFirstName(std::string firstNameToSet) { this->firstName = firstNameToSet; }

//LastName
const std::string Student::getLastName() const { return this->lastName; }
void Student::setLastName(std::string lastNameToSet) { this->lastName = lastNameToSet; }

//EmailAddress
const std::string Student::getEmailAddress() const { return this->emailAddress; }
void Student::setEmailAddress(std::string emailAddressToSet)
{
    this->emailAddress = emailAddressToSet;
}

//Age
const int Student::getAge() const { return this->age; }
void Student::setAge(int ageToSet) { this->age = ageToSet; }

//DaysInCourses
const int* Student::getDaysInCourses() const { return this->daysInCourses; }
void Student::setDaysInCourses(int course, int daysInCourseToSet)
{
    this->daysInCourses[course] = daysInCourseToSet;
}

//DegreeProgram
const Degree::DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }
void Student::setDegreeProgram(Degree::DegreeProgram degreeProgramToSet)
{
    this->degreeProgram = degreeProgramToSet;
}
