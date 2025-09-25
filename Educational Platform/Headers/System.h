#ifndef EDUCATIONAL_PLATFORM_SYSTEM_H
#define EDUCATIONAL_PLATFORM_SYSTEM_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <Doctor.h>
#include <Student.h>
#include <set>
#include <Course.h>
#include <AssignmentAnswer.h>

using namespace std;
class System
{
private:
    map <string , Student> Students;
    map <string , Doctor> Doctors;
    vector <AssignmentAnswer> AssignmentsAnswers;
    map <string , set <string>> Solved;
    vector <Course> Courses;
    map <string , vector <string>> Lectures;
public:
    void LoadData();
    void UploadData();
    void Startup();
    void DoctorLogin(vector <AssignmentAnswer> AssignmentsAnswers);
    void StudentSignup();
    void StudentLogin();
    void Login();
    void SignUp();
    void Exit();
    void Debug();
};

#endif