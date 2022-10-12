#pragma once
#include "student.h"

class Roster {
	
public:
	
	//Constructor
	Roster();
	//Destructor
	~Roster();

	string degreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

	//Public attribute
	Student* classRosterArray[5];

	//Public methods
	void parse(string);
	void add(string, string, string, string, int, int, int, int, degreeProgram); //Requirement E3A
	void remove(string); //Requirement E3B
	void printAll(); //Requirement E3C
	void printAverageDaysInCourse(string); //Requirement E3D
	void printInvalidEmails(); //Requirement E3E
	void printByDegreeProgram(degreeProgram); //Requirement E3F
};