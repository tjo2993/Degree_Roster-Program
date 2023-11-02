#include "roster.h"


int main() {

	/*Requirement for section F part 1*/
	cout << "Course: C867 Scripting and Programming - Applications\n"; 
	cout << "Programming Language: C++\n";
	cout << "Student ID: 010761648\n";
	cout << "Name: Troy Jones\n" << std::endl;


	/*Part A which includes my information as student ID A5*/
	const string studentData[] = {
			"A1,     John,Smith    ,John1989@gm ail.com   ,20,30,35,40,SECURITY",
			"A2,     Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,     Jack,Napoli   ,The_lawyer99yahoo.com ,19,20,40,33,SOFTWARE",
			"A4,     Erin,Black    ,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,     Troy,Jones    ,tjo2993@wgu.edu       ,35,14,21, 7,SOFTWARE"
	};

	const int Student_Roster_Count = 5;

	/*Creates instance of Roster class*/
	Roster classRoster;

	/*Adds each student to roster*/
	for (int i = 0; i < Student_Roster_Count; i++) classRoster.parse(studentData[i]);
	cout << "Student Roster Total:" << std::endl;
	classRoster.printAll();
	cout << std::endl;


	/*Software Students printed out*/
	cout << "Software Students:" << std::endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << std::endl;

	/*Network Students printed out*/
	cout << "Network Students:" << std::endl;
	classRoster.printByDegreeProgram(DegreeProgram::NETWORK);
	cout << std::endl;

	/*Security Students printed out*/
	cout << "Security Students:" << std::endl;
	classRoster.printByDegreeProgram(DegreeProgram::SECURITY);
	cout << std::endl;

	/*Display invalid emails*/
	cout << "Displaying Invalid Emails:" << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	/*Average number of days for course completion*/
	cout << "Course Duration Averages In Days:" << std::endl;
	for (int i = 0; i < Student_Roster_Count; i++) {
		classRoster.printAverageDaysInCourse(classRoster.class_Roster_Array[i]->getstudentID());
	}
	cout << std::endl;

	/*Student with ID A3 being removed from roster*/
	cout << "Student Being Removed From Roster:" << std::endl;
	classRoster.Remove_By_Student_ID("A3");
	cout << std::endl;

	/*Student with ID A3 being removed from roster results in error*/
	cout << "Student Being Removed From Roster:" << std::endl;
	classRoster.Remove_By_Student_ID("A3");
	cout << std::endl;

	system("pause");
	return 0;
}