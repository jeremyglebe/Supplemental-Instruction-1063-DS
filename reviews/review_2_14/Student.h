#include<string>
#include<iostream>
using namespace std;

class Student{
    private:
        float gpa;
    public:
        string mid;
        string fname;
        string lname;
        Student();
        Student(string mnumber, string studentFName, string studentLName, float grade);
        ~Student();
        float getGPA();
        void setGPA(float newGPA);
        void marry(Student& other);
};