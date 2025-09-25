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
    Student (string Name , string Id , string Mail , string Password , vector <string> Courses)
    {
        this -> Name = Name;
        this -> Id = Id;
        this -> Mail = Mail;
        this -> Password = Password;
        this -> Courses = Courses;
    }
    string GetMail() {return Mail;}
    string GetName() {return Name;}
    string GetPassword() {return Password;}
    string GetId() {return Id;}
    void Print()
    {
        cout << Name << " " << Id << " " << Mail << " "  << Password << " " ;
        for (auto i : Courses) cout << i << " ";
        cout << '\n';
    }
    void StudentPortal(vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);

    void Actions(string ChosenCourse , vector <Course> &AllCourse , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void Study(string ChosenCourse , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void ShowAssignments(string ChosenCourse , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
    void SubmitAssignment(string ChoisenCourse , string ChoicenAssignment , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved);
};

#endif