//
//  student.cpp
//  c867
//
//  Created by Danny Sirikhoth on 6/1/22.
//
#include "student.h"
#include<string>
#include <vector>
#include<iomanip>
#include<iostream>

using namespace std;

//------------constructor definition ------------------------
Student::Student()
{
    
}


 Student::Student(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram)
{
     this-> studentId = studentId;
     this-> firstName = firstName;
     this->lastName = lastName;
     this-> email = email;
     this-> age = age;
     this-> degreeProgram = degreeProgram;
     for(int i =0; i < size; i++)
     {
         this->days[i] = days[i];
         
     }
     return;
}

//------------print function-------------------------
void Student::print()
{
    cout << "StudentID:  " + studentId + "\t";
    cout << "First Name: " + firstName + "\t";
    cout << "Last Name:  " + lastName + "\t";
    cout << "Email:      " + email + "\t";
    cout << "Age:        "<< age << "\t";
   // cout << "Degree:     " << degreeProgram << "\n";
}


//---------------Setters----------------------
void Student::setstudentId(std::string studentId) { 
    this -> studentId = studentId;
}

void Student::setfirstName(std::string firstName) { 
    this-> firstName = firstName;
}

void Student::setlastName(std::string lastName) { 
    this -> lastName = lastName;
}

void Student::setemail(std::string email) { 
    this-> email = email;
}

void Student::setage(int age) { 
    this-> age = age;
}

void Student::setdays(int days[]) {
    for(int i =0; i < size; i++)
    {
        this-> days[i] = days[i];
    }
}

void Student::setdegreeProgram(DegreeProgram degreeProgram) {
    this-> degreeProgram = degreeProgram;
}

//------------Getters-------------
std::string Student::getstudentID() { 
    return this-> studentId;
}

std::string Student::getfirstName() { 
    return this-> firstName;
}

std::string Student::getlastName() { 
    return this-> lastName;
}

std::string Student::getemail() { 
    return this-> email;
}

int Student::getage() { 
    return this-> age;
}

int* Student::getdays() {
    return this-> days;
}

DegreeProgram Student::getdegreeProgram() { 
    return this-> degreeProgram;
}
//-------------Destructor-----------
Student::~Student(){};

