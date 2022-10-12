#include "student.h"
#include "degree.h"
#include "roster.h"

Student::Student() {
	studentID = "0"; //Requirement D1 + D2D
	firstName = "0"; //
	lastName = "0"; //
	emailAddress = "0"; //
	age = 0; //
	daysToComplete[0] = 0; //
	daysToComplete[1] = 0; //
	daysToComplete[2] = 0; //
	degreeIn = SOFTWARE; //
}

Student::Student(string a, string b, string c, string d, int e, int f1, int f2, int f3, enum degreeProgram g) {
	studentID = a; //Requirement D1 + D2D
	firstName = b; //
	lastName = c; //
	emailAddress = d; //
	age = e; //
	daysToComplete[0] = f1; //
	daysToComplete[1] = f2; //
	daysToComplete[2] = f3; //
	degreeIn = g; //
}
Student::~Student() {}

//Print
//Description: Prints student object attributes given a student ID
//Input: Student object pointer array, Student ID
//Output: iostream of the respective student object
//Used in: Roster::PrintAll, Roster::PrintByDegreeProgram
void Student::print(Student* student, string iD) { //Requirement D2E
	string p; 
	string q; 
	int i = 0; 
	while ((student+i)->getID() != iD) { 
		i++; 
	} 
	p = (student+i)->getID() + "\t" + (student + i)->getFirstName() + "\t" + (student + i)->getLastName() + "\t" + to_string((student + i)->getAge()) + "\t{" + to_string(*((student + i)->getDaysToComplete())) + "," + to_string(*((student + i)->getDaysToComplete() + 1)) + "," + to_string(*((student + i)->getDaysToComplete() + 2)) + "}\t" + (student + i)->getDegreeIn() + "\n"; 
	cout << p; 
}

void Student::setID(string iD) { //Requirement D2A + D2B all the way down
	studentID = iD;
}

string Student::getID() { 
	return studentID;

}

void Student::setFirstName(string name) {
	firstName = name;
}
string Student::getFirstName() {
	return firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;

}
string Student::getLastName() {
	return lastName;
}

void Student::setEmail(string email) {
	emailAddress = email;
}
string Student::getEmail() {
	return emailAddress;
}

void Student::setAge(int age) {
	this->age = age;

}
int Student::getAge() {
	return age;
}

void Student::setDaysToComplete(int vect[3]) {
	daysToComplete[0] = vect[0];
	daysToComplete[1] = vect[1];
	daysToComplete[2] = vect[2];
}
int* Student::getDaysToComplete() {
	return daysToComplete;
}

void Student::setDegreeIn(enum degreeProgram degree) {
	degreeIn = degree;

}
string Student::getDegreeIn() {
	return degreeProgramStrings[degreeIn];
}