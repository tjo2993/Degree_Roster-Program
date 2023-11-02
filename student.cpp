#include "student.h"

/*Constructor is created  and is set to default*/
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	/*Sets the value to the default (0) for each day*/
	for (int i = 0; i < course_days_Array; i++) this->course_duration[i] = 0;
	/*Sets the default value of Security for the enumerated data type*/
	this->degreeProgram = DegreeProgram::SECURITY;
}

/*Pointer is set*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < course_days_Array; i++) this->course_duration[i] = days[i];
	this->degreeProgram = degreeProgram;
}


/*Creates getters for each column of the student roster per D1*/
string Student::getstudentID() {
	return this->studentID;
}
string Student::getfirstName() {
	return this->firstName;
}
string Student::getlastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getstudentAge() {
	return this->age;
}
int* Student::getcourseDays() {
	return this->course_duration;
}
DegreeProgram Student::getBy_Degree_Program() {
	return this->degreeProgram;
}

/*Creates setters for each column of the student roster per D1*/
void Student::setStudent_ID(string studentID) {
	this->studentID = studentID;
}
void Student::setStudent_First_Name(string firstName) {
	this->firstName = firstName;
}
void Student::setStudent_Last_Name(string lastName) {
	this->lastName = lastName;
}
void Student::setStudent_Email_Address(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setStudent_Age(int age) {
	this->age = age;
}
void Student::setCourse_Days(int course_days[]) {
	for (int i = 0; i < course_days_Array; i++) this->course_duration[i] = course_days[i];
}
void Student::setDegree_Program_Type(DegreeProgram degree_program) {
	this->degreeProgram = degree_program;
}


/*Print Defined*/
void Student::print() {
	/*Tabs each string*/
	cout << this->getstudentID() << '\t';
	cout << this->getfirstName() << '\t';
	cout << this->getlastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getstudentAge() << '\t';
	cout << this->getcourseDays()[0] << ',';
	cout << this->getcourseDays()[1] << ',';
	cout << this->getcourseDays()[2] << '\t';
	cout << Degree_Program_String[this->getBy_Degree_Program()] << '\n';

}