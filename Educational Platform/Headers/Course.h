#ifndef EDUCATIONAL_PLATFORM_ASSIGNMENTS_H
#define EDUCATIONAL_PLATFORM_ASSIGNMENTS_H
#include <iostream>
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
    AssignmentAnswer (const string &Title , const string &Course ,const string &StudentId ,const string &Answer)
    : Title(Title), Course(Course), StudentId(StudentId), Answer(Answer) {}

    void Print () const
    {
        cout << Title << " " << Course << " "  << StudentId << " "  << Answer << " "  << "\n";
    }
    const string &GetCourse() {return Course;}
    const string &GetId() {return StudentId;}
    const string &GetAnswer() {return Answer;}
    const string &GetTitle () {return Title;}
    bool operator < (const AssignmentAnswer &Answer1) const {return this -> Title < Answer1.Title;}
};
#endif
