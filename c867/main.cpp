//
//  main.cpp
//  c867
//
//  Created by Danny Sirikhoth on 6/1/22.
//

#include <iostream>
#include "roster.h"
using namespace std;

int main() {
    
    
    
    int studentNo =5;
    const std::string studentData[5] =

    {   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Danny,Sirikhoth,Dsirikh@wgu.edu,29, 10,15,20,SOFTWARE"
        
    };
    //----------F1--------------
    cout << " Course title: C867 Scripting and Programming Applications \n";
    cout << " Programming language : C++ \n";
    cout << " Wgu StudentID: 010186960         Name: Danny Sirikhoth \n" << "\n";

    //-------F2----------------
    Roster classRoster(studentNo);
    
    //-------F3---------------
    for(int i =0; i < studentNo; i++)
    {
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();
    
    cout <<"\n ";
    classRoster.printInvalidEmails();
    //--------F4--------------------
    //-------print average days left in the course--------
    cout <<"\n ";
    for(int i =0; i < studentNo; i++)
    {
        classRoster.printAverageDays(classRoster.getStudent(i)->getstudentID());
    }
   
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");
    
    
    return 0;
}
