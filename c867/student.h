//
//  student.h
//  c867
//
//  Created by Danny Sirikhoth on 6/1/22.
//



#define student_h

#include"degree.h"
#include<string>
#include<vector>

using namespace std;
//D1 define the student class
class Student{
    public:
    
    //Default Constructor
    Student();
    
    //Constructor
    Student(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
    
    //Variable declarations
    
    const static int size =3;
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[size];
    DegreeProgram degreeProgram;
    
    // D2E Declare the print function
    void print();

    //D2A Declare getters
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemail();
    int getage();
    int* getdays();
    DegreeProgram getdegreeProgram();

    //D2B Declare Setters
    void setstudentId(string studentId);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemail(string email);
    void setage(int age);
    void setdays(int days[]);
    void setdegreeProgram(DegreeProgram degreeProgram);
    
    //Destructor
    ~Student();

};




