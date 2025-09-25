#ifndef EDUCATIONAL_PLATFORM_COURSES_H
#define EDUCATIONAL_PLATFORM_COURSES_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Course
{
private:
    string Title;
    string DoctorName;
    string DoctorMail;
    vector <string> StudentId;
    vector <string> Assignments;
public:
    Course (string Title , string DoctorName , string DoctorMail , vector<string> StudentId , vector <string> Assignments)
    {
        this -> Title = Title;
        this -> DoctorName = DoctorName ;
        this -> DoctorMail = DoctorMail;
        this -> StudentId = StudentId;
        this -> Assignments = Assignments;
    }
    void Print ()
    {
        cout << Title << " " << DoctorName << " " << DoctorMail << " ";
        for (auto id : StudentId ) cout << id << " ";
        for (auto Assignment : Assignments ) cout << Assignment << " ";
        cout << "\n";
    }
    string GetName() {return Title;}
    vector <string> GetAssignments () {return Assignments;}
};
#endif