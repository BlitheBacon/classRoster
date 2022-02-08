#include <iostream>
#include <string>
#include "degree.hpp"
#include "student.hpp"
#include "roster.hpp"

Student* parse(std::string);

int main() {
    //Input student data
    const std::vector<std::string> studentData = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,James,Peck,j.peck@gmail,29,15,32,26,SOFTWARE"
    };
    //Roster initialization
    Roster classRoster;
    
    //Loops through studentData to parse and add students to the roster
    for (int i = 0; i < studentData.size(); i++) {
        classRoster.parse(studentData[i]);
    }
    
    //Printing requested data
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (int i = 0; i < classRoster.classRosterArray.size(); i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    classRoster.printByDegreeProgram(Degree::SOFTWARE);
    classRoster.removeByID("A3");
    classRoster.printAll();
    classRoster.removeByID("A3");
    
    return 0;
}
