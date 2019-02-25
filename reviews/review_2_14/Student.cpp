#include "Student.h"

Student::Student(){
    mid = "M00000000";
    fname = "John";
    lname = "Doe";
    gpa = 2.0;
}

Student::Student(string mnumber, string studentFName, string studentLName, float grade){
    mid = mnumber;
    fname = studentFName;
    lname = studentLName;
    gpa = grade;
}

Student::~Student(){
    cout << "The student is dead.\n";
}

float Student::getGPA(){
    return gpa;
}

void Student::setGPA(float newGPA){
    if(newGPA > 0 && newGPA <= 4.0)
        gpa = newGPA;
    else
        cout << "GPA must be between 0.00 and 4.00\n";
}

void Student::marry(Student& other){
    lname = other.lname;
}