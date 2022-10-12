#include "student.h"
#include "degree.h"
#include "roster.h"
#include <string>
#include <regex>

//Constructor
Roster::Roster() { //Requirement E1
	classRosterArray[0] = 0; //
	classRosterArray[1] = 0; //
	classRosterArray[2] = 0; //
	classRosterArray[3] = 0; //
	classRosterArray[4] = 0; //
}
//Destructor 
Roster::~Roster() { //Requirement F5
	std::cout << "DONE.";
}

//Parse
//Description: Separates an conjoined array of strings into Student object attributes
//Input: StudentData table array at a single index ex: obj = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"
//Output: Call to Roster add() function with the parsed parameters A1, John, etc...
//Used in: main.cpp
void Roster::parse(string obj) { //Requirement E2A 
	size_t rhs = obj.find(","); 
	string iD = obj.substr(0, rhs); 

	size_t lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string firstName = obj.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string lastName = obj.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string email = obj.substr(lhs, rhs - lhs); 

	lhs = rhs + 1;
	rhs = obj.find(",", lhs); 
	string aged = obj.substr(lhs, rhs - lhs); 
	int age = stol(aged); 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string days1 = obj.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string days2 = obj.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string days3 = obj.substr(lhs, rhs - lhs); 

	int days[3] = { std::stol(days1), std::stol(days2), std::stol(days3) }; 

	lhs = rhs + 1; 
	rhs = obj.find(",", lhs); 
	string degreeP = obj.substr(lhs, rhs - lhs); 
	degreeProgram program = SECURITY; 
	if (degreeP == "NETWORK") { 
		program = NETWORK; 
	}else if (degreeP == "SECURITY") { 
		program = SECURITY; 
	}else if (degreeP == "SOFTWARE") { 
		program = SOFTWARE; 
	} 

	Roster::add(iD, firstName, lastName, email, age, stoi(days1), stoi(days2), stoi(days3), program);
}

//Add
//Description: Adds a created student object to the classRosterArray attribute
//Input: Separated parsed strings and other data types to create a new Student object via the StudentData table originally in main.cpp
//Output: With each call adds one Student object to the Roster class variable classRosterArray 
//Used in: Parse
void Roster::add(string iD, string firstName, string lastName, string email, int age, int days1, int days2, int days3, degreeProgram program) {
	Student* p; 
	p = new Student();
	p->setID(iD);	//Requirement D2B + D2C + E1 + E2 + E2B + E3A
	p->setFirstName(firstName); 
	p->setLastName(lastName); 
	p->setEmail(email); 
	p->setAge(age); 
	int arr[3] = { days1, days2, days3}; 
	p->setDaysToComplete(arr); 
	p->setDegreeIn(program); 
	int i = 0; 
	while (classRosterArray[i] != 0 && i <= 4) { 
		i++; 
	} 
	classRosterArray[i] = p; 
}

//Remove
//Description: Removes a student object from the classRosterArray attribute
//Input: Student ID
//Output: Assigns Zero value to the appropriate classRosterArray attribute, exceptions if empty
//Used in: main.cpp
void Roster::remove(string iD) { //Requirement E3B
	cout << endl;
	int i = 0;
	while (i < 5 && classRosterArray[i]->getID() != iD) {
		i++;
	}
	cout << "Removing " << iD << endl;;
	if (i == 5) {
		cout << "Error: The student ID could not be located!" << endl;
	}
	else {
		classRosterArray[i]->setID("0");
	}
	
}

//PrintAll
//Description: Prints all populated student objects in Roster::classRosterArray attribute
//Input: None
//Output: iostream of all classRosterArray student objects
//Used in: main.cpp
void Roster::printAll() { //Requirement E3C 
	int i = 0; 
	while (i <= 4) { 
		if (classRosterArray[i]->getID() != "0") { 
			Student::print(classRosterArray[i], classRosterArray[i]->getID()); 
		} 
		i++; 
	} 
}

//Print Average Days Per Course
//Description: Given a student ID, determines the average days per course by summing days and dividing by three
//Input: Student ID
//Output: iostream average days per course
//Used in: main.cpp
void Roster::printAverageDaysInCourse(string iD) { //Requirement E3D
	int i = 0; 
	while (classRosterArray[i]->getID() != iD) { 
		i++; 
	} 
	int* p; 
	p = classRosterArray[i]->getDaysToComplete(); 
	int sum = *p + *(p + 1) + *(p + 2); 
	cout << "The average days in courses for student " << iD << " is: " << sum / 3 << endl; 
} 

//Print Invalid Emails
//Description: References this object's classRosterArray and regex checks for any invalid emails and outputs invalid emails
//Input: None
//Output: iostream invalid email addresses in Roster::classRosterArray
//Used in: main.cpp
void Roster::printInvalidEmails() { //Requirement E3E
	cout << endl; 
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); 
	string arr[5]; 
	string arra; 
	int j = 0; 

	for (int i = 0; i <= 4; i++) { 
		arra = classRosterArray[i]->getEmail(); 
		if (!regex_match(arra, pattern)) { 
			arr[j] = arra; 
			j++; 
		} 
		else { 
			continue; 
		} 
	} 
	int i = 0; 
	string compile;  

	if (j == 0) { 
		cout << "No invalid emails are found in the roster."; 
	} 
	else { 
		while (i<5 && arr[i] != "") { 
			compile = compile + arr[i] + "\n"; 
			i++; 
		} 
		cout << "Invalid emails found in roster: " << endl << compile << endl; 
	} 
		
}

//Print by Degree Program
//Description: Prints solely the students of a specific degree program for all student objects within the Roster::classRosterArray attribute
//Input: Desired degree type to specify students by
//Output: iostream of students matching the degree type input
//Used in: main.cpp
void Roster::printByDegreeProgram(degreeProgram degree) { //Requirement E3F
	cout << endl; 
	int i = 0; 
	int j = 0;
	cout << "Students with a degree in " << degreeProgramStrings[degree] << ":" << endl; 
	while (i <= 4) { 
		if (classRosterArray[i]->getDegreeIn() != degreeProgramStrings[degree]) { 
			i++; 
		} 
		else { 
			Student::print(classRosterArray[i], classRosterArray[i]->getID()); 
			i++; 
			j = 1; 
		} 
	}
	if (j == 0) { 
		cout << "None" << endl; 
	} 
}

