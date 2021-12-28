#include <iostream>
#include <string>
#include "degree.hpp"
#include "student.hpp"
#include "roster.hpp"

Student* parse(std::string);

int main() {
    //Test data
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Josh,Hagins,jhagins@gmail.com,29,15,32,26,SOFTWARE"
    };
    Student* classRosterArray[5];
    classRosterArray[0] = parse(studentData[0]);
    classRosterArray[0]->print();
    
    //Previous work was implementing Roster and making adjustments to Student
    
    return 0;
}
