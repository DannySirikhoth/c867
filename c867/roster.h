//
//  roster.h
//  c867
//
//  Created by Danny Sirikhoth on 6/1/22.
//

#pragma once
#include "student.h"
#include <string>
#include <iostream>
using std::cout;

class Roster {

public:
    int lastIndex;
    int maxSize =5;

    //------------E1 CREATE AN Array of Pointers-------------
    Student** classRosterArray;
    
    
    //-----------Default Constructor-----------------------
    Roster();
    Roster(int maxSize);
    
    
    //------------E2 Parse -------------------------------
    void parse (string row);
    
    //------------------E3A Add------------------------
    void add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    
    Student* getStudent(int index);
    
    
    //-------------------E3B Remove----------------------
    bool remove (string studentId);

    //-------------------E3C Print All---------------------
    void printAll();
    
    //---------------------E3D Print Average Days in course-----
    void printAverageDays(string studentId);
    
    //-------------------E3E Print Invalid Emails--------------
    void printInvalidEmails();
    
    //--------------------E3F Print Degree Program------------
    void printByDegreeProgram(DegreeProgram degreeProgram);



    //---------------------Destructor-------------------------
    ~Roster();
};
