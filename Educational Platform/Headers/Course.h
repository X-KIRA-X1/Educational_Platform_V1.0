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
    Course (const string &Title , const string &DoctorName , const string &DoctorMail , const vector<string> &StudentId , const vector <string> &Assignments)
    : Title(Title ) , DoctorName(DoctorName) , DoctorMail(DoctorMail) , StudentId (StudentId)  , Assignments(Assignments){}
    void Print () const
    {
        cout << Title << " " << DoctorName << " " << DoctorMail << " ";
        for (auto id : StudentId ) cout << id << " ";
        for (auto Assignment : Assignments ) cout << Assignment << " ";
        cout << "\n";
    }
    const string &GetName() {return Title;}
    const vector <string> &GetAssignments () {return Assignments;}
};
#endif
