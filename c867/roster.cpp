//
//  roster.cpp
//  c867
//
//  Created by Danny Sirikhoth on 6/1/22.
//
#include "roster.h"



using namespace std;

//-------------Constructor--------------

Roster::Roster()
{
   this->maxSize = 0;
   this->lastIndex =-1;
   this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
   this->maxSize = maxSize;
   this->lastIndex = -1;
   this->classRosterArray = new Student * [maxSize];
}



//-------------E2A Parse---------------
void Roster::parse(string row)
{
   int parseArr[Student::size];
   //DegreeProgram degreeprogram;

   if (lastIndex < maxSize)
   {
       lastIndex++;
   }
  
   this->classRosterArray[lastIndex] = new Student();
    
    
   //Parse through the student data strong deliminated by comma
   //read student ID
   int long rhs = row.find(",");
   classRosterArray[lastIndex]->setstudentId(row.substr(0, rhs));

   // firstName
   int long lhs = rhs + 1;
   rhs = row.find(",", lhs);
   classRosterArray[lastIndex]->setfirstName(row.substr(lhs, rhs - lhs));

   // lastName
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   classRosterArray[lastIndex]->setlastName(row.substr(lhs, rhs - lhs));

   //email
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   classRosterArray[lastIndex]->setemail(row.substr(lhs, rhs - lhs));

   // age
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   int x = stoi(row.substr(lhs, rhs - lhs));
   classRosterArray[lastIndex]->setage(x);

   //daysInCourse1
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   parseArr[0]= stoi(row.substr(lhs, rhs - lhs));

   // daysInCourse2
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   parseArr[1] = stoi(row.substr(lhs, rhs - lhs));

   // daysInCourse3
   lhs = rhs + 1;
   rhs = row.find(",", lhs);
   parseArr[2] = stoi(row.substr(lhs, rhs - lhs));

   //set the days left in the course
   classRosterArray[lastIndex]->setdays(parseArr);

   //read degree program
   lhs = rhs + 1;
   if (row[lhs] == 'S')
       {
           if (row[lhs + 1] == 'E') classRosterArray[lastIndex]->setdegreeProgram(SECURITY);
           else if (row[lhs + 1] == 'O') classRosterArray[lastIndex]->setdegreeProgram(SOFTWARE);
           else
           {
               cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
               exit(-1);
           }
       }
       else if (row[lhs] == 'N') classRosterArray[lastIndex]->setdegreeProgram(NETWORK);
       else
       {
           cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
           exit(-1);
       }
}

//--------- E3A updates the roster------------------------
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
{
   int arrDaysToComplete[Student::size];

   arrDaysToComplete[0] = daysInCourse1;
   arrDaysToComplete[1] = daysInCourse2;
   arrDaysToComplete[2] = daysInCourse3;

   classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrDaysToComplete, degreeprogam);
}

Student* Roster::getStudent(int index)
{
   return classRosterArray[index];
}


//----------------E3B remove students from the roster by ID----------
bool Roster::remove(string studentID)
{
   bool found = false;
   for (int i = 0; i <= lastIndex; i++)
   {
       if (this->classRosterArray[i]->getstudentID() == studentID)
       {
           found = true;
           delete this->classRosterArray[i];
           this->classRosterArray[i] = this->classRosterArray[lastIndex];
           lastIndex--;
       }
   }
   if (!found)
   {
       cout << "Student with ID " << studentID << " not found." << endl;
   }
   return found;
}

//---------------E3C Prints a complete list of student data-------
void Roster::printAll()
{
   for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

//-------------E3D print average days in course-----------------------
void Roster::printAverageDays(string sID)
{
   bool found = false;
   for (int i = 0; i <= lastIndex; i++)
   {
       if (this->classRosterArray[i]->getstudentID() == sID)
       {
           found = true;
           int* ptr = classRosterArray[i]->getdays();
           cout << "Average number of days left in class for " << sID << " is " << (ptr[0] + ptr[1] + ptr[2]) / 3 << "\n";
       }
   }
   if (!found) cout << "Student not found!\n";
}

//-------------------E3E Print Invalid Emails-----------------------
void Roster::printInvalidEmails()
{
   cout << "--------------Displaying invalid email entries-------------\n";
   for (int i = 0; i < 5; i++)
   {
       string email = classRosterArray[i]->getemail();
       if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
           cout << email << endl;
   }
}

//--------------------E3F Print by Degree Program--------------
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
   cout << "Printing by degree " << DegreeProgramStrings[degreeprogram] << endl;
   for (int i = 0; i <= lastIndex; i++) {
       if (this->classRosterArray[i]->getdegreeProgram() == degreeprogram) this->classRosterArray[i]->print();
   }
}

//-----------Destructor-------------------------
Roster::~Roster()
{
   
   delete this-> classRosterArray;
}
