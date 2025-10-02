#ifndef EDUCATIONAL_PLATFORM_ASSIGNMENTS_H
#define EDUCATIONAL_PLATFORM_ASSIGNMENTS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class AssignmentAnswer
{
private :
    string Title;
    string Course;
    string StudentId;
    string Answer;
public :
    AssignmentAnswer (string Title , string Course , string StudentId , string Answer)
    {
        this -> Title = Title;
        this -> Course = Course;
        this -> StudentId = StudentId;
        this -> Answer = Answer;
    }
    void Print ()
    {
        cout << Title << " " << Course << " "  << StudentId << " "  << Answer << " "  << "\n";
    }
    const string &GetCourse() {return Course;}
    const string &GetId() {return StudentId;}
    const string &GetAnswer() {return Answer;}
    const string &GetTitle () {return Title;}
    bool operator < (AssignmentAnswer Answer1) {return this -> Title < Answer1.Title;}
};
#endif //EDUCATIONAL_PLATFORM_ASSIGNMENTS_H
