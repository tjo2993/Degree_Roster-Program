#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;

class Student {
public:
	const static int course_days_Array = 3;
	/*Constructor Function Set*/
	Student(); /*Parameterless*/
	/*Fully set*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int course_duration[], DegreeProgram degreeProgram);

	/*accessor/getter*/
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getEmailAddress();
	int getstudentAge();
	int* getcourseDays();
	DegreeProgram getBy_Degree_Program();

	/*mutator/setter*/
	void setStudent_ID(string ID);
	void setStudent_First_Name(string firstName);
	void setStudent_Last_Name(string lastName);
	void setStudent_Email_Address(string emailAddress);
	void setStudent_Age(int age);
	void setCourse_Days(int course_duration[]);
	void setDegree_Program_Type(DegreeProgram degree_P);

	/*Print function for specific data*/
	void print();


private:
	/*Makes it only accessible to the object*/
	string studentID, firstName, lastName, emailAddress;
	int age;
	int course_duration[course_days_Array];
	DegreeProgram degreeProgram;

};