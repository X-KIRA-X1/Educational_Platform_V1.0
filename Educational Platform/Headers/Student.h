#ifndef EDUCATIONAL_PLATFORM_STUDENT_H
#define EDUCATIONAL_PLATFORM_STUDENT_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Course.h"
using namespace std;
class Student
{
private :
    string Name;
    string Id;
    string Mail;
    string Password;
    vector <string> Courses;

public :
    Student (){}
    Student (const string &Name , const string &Id , const string &Mail , const string &Password , const vector <string> &Courses)
    : Name(Name) , Id(Id) , Mail(Mail) , Password(Password) , Courses(Courses){}
    const string &GetMail() {return Mail;}
    const string &GetName() {return Name;}
    const string &GetPassword() {return Password;}
    const string &GetId() {return Id;}
    void Print() const
    {
        cout << Name << " " << Id << " " << Mail << " "  << Password << " " ;
        for (auto i : Courses) cout << i << " ";
        cout << '\n';
    }
    void StudentPortal(vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);

    void Actions(const string &ChosenCourse , vector <Course> &AllCourse , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void Study(const string &ChosenCourse , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void ShowAssignments(const string &ChosenCourse , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void SubmitAssignment(const string &ChosenCourse , const string &ChosenAssignment , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
};

#endif
