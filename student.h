#pragma once
#include <string>
#include <vector>
#include "degree.h"
#include <iostream>
using namespace std;

class Student
{
private:
	string studentID; // Requirement D1
	string firstName; //
	string lastName; //
	string emailAddress; //
	int age; //
	int daysToComplete[3]; //
	enum degreeProgram degreeIn; //

public:
	string degreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

	//Constructors
	Student(); //Requirement D2D
	Student(string, string, string, string, int, int, int, int, enum degreeProgram); //

	//Destructor
	~Student();

	//Public method
	static void print(Student*, string iD);

	//Setters and getters
	void setID(string);
	string getID();

	void setFirstName(string);
	string getFirstName();

	void setLastName(string studentID);
	string getLastName();

	void setEmail(string studentID);
	string getEmail();

	void setAge(int);
	int getAge();

	void setDaysToComplete(int[3]);
	int* getDaysToComplete();

	void setDegreeIn(enum degreeProgram);
	string getDegreeIn();

	

};