#include "Student.h"
#include <iostream>
#include "roster.h"
using namespace std;
int main()
{
    //Requirement F1
    cout << "C867 - SCripting & Programming: Applications" << endl << "Language : C++" << endl << "Student ID : 010674754" << endl << "Name : Martin Havens" << endl << endl;

    const string studentData[5] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoocom,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcastnet,22,50,58,40,SECURITY",
        "A5,Martin,Havens,martinhavensds@gmailcom,23,13,12,11,SOFTWARE" //Requirement A & B
    };
        
        Roster classRoster; //Requirement F2
        classRoster.parse(studentData[0]); //Requirement F3
        classRoster.parse(studentData[1]); //
        classRoster.parse(studentData[2]); //
        classRoster.parse(studentData[3]); // 
        classRoster.parse(studentData[4]); //

        cout << "Dislaying all students:" << endl;
        classRoster.printAll(); //Requirement F3 + F4

        classRoster.printInvalidEmails();
        for (int i = 0; i <= 4; i++) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
        }

        classRoster.printByDegreeProgram(SOFTWARE);
        classRoster.remove("A3");
        classRoster.printAll();
        classRoster.remove("A3");

        //classRoster.~Roster(); //Requirement F5 however, it is automatically called at the end of main.

        return 0;

}       