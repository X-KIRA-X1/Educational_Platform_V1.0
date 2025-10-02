#ifndef EDUCATIONAL_PLATFORM_DOCTOR_H
#define EDUCATIONAL_PLATFORM_DOCTOR_H
#include <iostream>
#include <vector>
#include <AssignmentAnswer.h>
using namespace std;

class Doctor
{
private:
    string Name;
    string Mail;
    string Password;
    vector <string> Courses;
public:
    Doctor (){}
    Doctor(const string &Name ,const string &Mail ,const string &Password ,const vector <string> &Courses)
        :Name(Name) , Mail(Mail) , Password(Password) , Courses(Courses){}
    void Print() const 
    {
        cout << Name << " " << Mail << " "  << Password << " " ;
        for (auto i : Courses) cout << i << " ";
        cout << '\n';
    }
    const string &GetPassword () {return Password;}
    void DoctorPortal(vector <AssignmentAnswer> &AssignmentsAnswers);
    void AddAssignment(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers);
    void ShowAssignmentsAnswers(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers);
    void AddLectureLink(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers);
    void AddGrade (string ChosenCourse , vector <AssignmentAnswer> &CourseAssignmentsAnswers ,  vector <AssignmentAnswer> &AssignmentsAnswers);
    void ShowGrades (string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers);

};


#endif
