#pragma once
#include <iostream>

#include "student.h"

class Roster {
public:
	int rosterIndex = -1;
	const static int DataTable = 5;
	Student* class_Roster_Array[DataTable];
	/*Parsing each set of data*/
	void parse(string row);
	/*Sets instance and updates roster*/
	void add(string Student_ID,
		string Student_First_Name,
		string Student_Last_Name,
		string Student_Email,
		int Student_Age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degree_P);
	/*Prints all students with tab separation*/
	void printAll();
	/*Print by degree program*/
	void printByDegreeProgram(DegreeProgram degree_P);
	/*Print by email*/
	void printInvalidEmails();
	/*Prints average day in completed course*/
	void printAverageDaysInCourse(string studentID);
	/*removes student by ID and creates error if not there*/
	void Remove_By_Student_ID(string studentID);
	/*Destructor*/
	~Roster();
};

