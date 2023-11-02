#include <string>

#include "roster.h"

/*This parses each row, one at a time*/
void Roster::parse(string Student_Data) {
	/*extracts substring in front of first comma found*/
	int leftSide = Student_Data.find(",");
	string Student_ID = Student_Data.substr(0, leftSide);
	/*moves past previous comma*/
	int rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	string Student_First_Name = Student_Data.substr(rightSide, leftSide - rightSide);
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	string Student_Last_Name = Student_Data.substr(rightSide, leftSide - rightSide);
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	string Student_Email = Student_Data.substr(rightSide, leftSide - rightSide);
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	int Student_Age = stoi(Student_Data.substr(rightSide, leftSide - rightSide));
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	int Days_In_Course1 = stoi(Student_Data.substr(rightSide, leftSide - rightSide));
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	int Days_In_Course2 = stoi(Student_Data.substr(rightSide, leftSide - rightSide));
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);
	int Days_In_Course3 = stoi(Student_Data.substr(rightSide, leftSide - rightSide));
	/*moves past previous comma*/
	rightSide = leftSide + 1;
	leftSide = Student_Data.find(",", rightSide);

	/*Loops through degree program types*/
	DegreeProgram degree_P = DegreeProgram::SECURITY;
	if (Student_Data.at(rightSide) == 'S' && Student_Data.at(rightSide + 1) == 'E') {
		degree_P = DegreeProgram::SECURITY;
	}
	else if (Student_Data.at(rightSide) == 'S' && Student_Data.at(rightSide + 1) == 'O') {
		degree_P = DegreeProgram::SOFTWARE;
	}
	else if (Student_Data.at(rightSide) == 'N') {
		degree_P = DegreeProgram::NETWORK;
	}

	add(Student_ID, Student_First_Name, Student_Last_Name, Student_Email, Student_Age, Days_In_Course1, Days_In_Course2, Days_In_Course3, degree_P);
}/*This combines strings and places into a created object*/



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourses2, int daysInCourses3, DegreeProgram degree_P) {
	int DaysInCourse[3] = { daysInCourse1,daysInCourses2,daysInCourses3 };

	class_Roster_Array[++rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, DaysInCourse, degree_P);

}


/*All Students In Roster are Displayed Under A Header*/
void Roster::printAll() {
	/*Header to indentify information for each student row*/
	cout << "Student ID|First Name|Last Name|          |Email Address|      |Age|    |Days in Courses|   |Degree Program|\n";
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		cout << class_Roster_Array[i]->getstudentID(); cout << '\t';
		cout << class_Roster_Array[i]->getfirstName(); cout << '\t';
		cout << class_Roster_Array[i]->getlastName(); cout << '\t';
		cout << class_Roster_Array[i]->getEmailAddress(); cout << '\t';
		cout << class_Roster_Array[i]->getstudentAge(); cout << '\t';
		cout << class_Roster_Array[i]->getcourseDays()[0]; cout << '\t';
		cout << class_Roster_Array[i]->getcourseDays()[1]; cout << '\t';
		cout << class_Roster_Array[i]->getcourseDays()[2]; cout << '\t';
		cout << Degree_Program_String[class_Roster_Array[i]->getBy_Degree_Program()] << std::endl;
	}
}


/*displays student with their degree program with header*/
void Roster::printByDegreeProgram(DegreeProgram degreeP) {
	/*Header for each student*/
	cout << "Student ID|First Name|Last Name|Email Address|Age|Days in Courses|Degree Program\n";
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (Roster::class_Roster_Array[i]->getBy_Degree_Program() == degreeP) class_Roster_Array[i]->print();
	}
	cout << std::endl;
}



void Roster::printInvalidEmails() {
	/*sets the student emails to initially false condition*/
	bool ALL = false;
	/*parses through each student's email for empty spaces, missing @ symbols, and missing periods before the domains */
	for (int i = 0; i <= rosterIndex; i++) {
		string Student_Email = (class_Roster_Array[i]->getEmailAddress());
		if (Student_Email.find('@') == string::npos || (Student_Email.find(' ') == string::npos && Student_Email.find('.') == string::npos)) {
			/*sets each email address to true that passes against 'test'*/
			ALL = true;
			/*Each email is printed out that matches conditions in the 'if' statement*/
			cout << Student_Email << std::endl;
		}
	}
}

/*Averages course day durations per student by student ID*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		/*Identified by studentID parameter*/
		if (class_Roster_Array[i]->getstudentID() == studentID) 
		{
			cout << studentID << ":";
			cout << (class_Roster_Array[i]->getcourseDays()[0] + class_Roster_Array[i]->getcourseDays()[1] + class_Roster_Array[i]->getcourseDays()[2]) / 3.0 << std::endl;
				
		}
	}
}

/*removes student by given ID*/
void Roster::Remove_By_Student_ID(string studentID) {
	bool remove_student = false;
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (class_Roster_Array[i]->getstudentID() == studentID) {
			remove_student = true;
			if (i < DataTable - 1) {
				Student* temp = class_Roster_Array[i];
				class_Roster_Array[i] = class_Roster_Array[DataTable - 1];
				class_Roster_Array[DataTable - 1] = temp;
			}
			Roster::rosterIndex--;
		}

	}
	if (remove_student) {
		cout << studentID << " removed." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " Student ID does not exist in roster!" << std::endl << std::endl;
}

/*Destructor is initialized and clearing memory.*/
Roster::~Roster() {
	cout << "Destructor Has Been Initialized And Executing!!!" << std::endl << std::endl;
	for (int i = 0; i < DataTable; i++) {
		delete class_Roster_Array[i];
		class_Roster_Array[i] = nullptr;
	}
}