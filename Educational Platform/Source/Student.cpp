#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include "Student.h"
#include "Course.h"
int InputValidation (int Range)
{
    int Choice; cin >> Choice;
    while(cin.fail() or Choice < 1 or Choice > Range)
    {
        cout << "Please enter a valid number : \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> Choice;
    }
    return Choice;
}
void Student :: StudentPortal (vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved)
{
    cout << "You are enrolled in " << Courses.size() << " courses : ";
    int CourseNumber = 1;
    for (string Course : Courses) cout << CourseNumber++ << "." << Course << " ";
    cout << "\n";
    cout << "Choose one course :  \n";
    int Choice = InputValidation(Courses.size());
    string ChosenCourse = Courses[Choice - 1];
    Actions(ChosenCourse , AllCourses , Links , Solved);
}
void Student :: Study(const string &ChosenCourse, vector <Course> &AllCourses , map <string , vector<string>> &Links , map <string , set <string>> &Solved)
{
    if (!Links[ChosenCourse].size()) cout << "There is no lectures to study! \n";
    else
    {
        cout << "There is " << Links[ChosenCourse].size() << " lectures \n";
        cout << "Enter the number of the lecture you want to study : \n";
        int Choice = InputValidation(Links[ChosenCourse].size());
        cout << Links[ChosenCourse][Choice - 1] << "\n";
    }
    cout << "1.Back to the last page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) Actions(ChosenCourse , AllCourses , Links , Solved);
    if (Action == 2) return;
}
void Student :: Actions(const string &ChosenCourse, vector<Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved)
{
    cout << "Select something to do : \n" << "1.Study\n2.Show Assignments\n3.Exit\n";
    int Action = InputValidation(3);
    if (Action == 1) Study(ChosenCourse , AllCourses  , Links , Solved);
    if (Action == 2) ShowAssignments(ChosenCourse , AllCourses , Links , Solved);
    if (Action == 3) return;
}
void Student :: ShowAssignments(const string &ChosenCourse, vector <Course> &AllCourses , map <string,vector<string>> &Links ,map <string , set <string>> &Solved)
{
    vector <string> Assignments;
    for (auto Course : AllCourses)
    {
        if (Course.GetName() == ChosenCourse) Assignments = Course.GetAssignments();
    }
    int AssignmentNum = 1;
    int solved = 0;
    for (string assignment : Assignments)
    {
        string asscor = assignment + ChosenCourse;
        cout << AssignmentNum++ << "." << assignment << " ";
        if (Solved[asscor].find(Id) == Solved[asscor].end()) cout << "(Unsolved)";
        else solved++ , cout << "(Solved)";
        cout << '\n';
    }
    cout << "1.Submit an assignment\n2.Back to the last page\n3.Exit\n";
    int Action = InputValidation(3);
    if (Action == 1)
    {
        if (solved == Assignments.size())
        {
            cout << "You have submitted all the assignments\n";
            cout << "1.Back to the last page\n2.Exit\n";
            int Action = InputValidation(2);
            if (Action == 1) Actions(ChosenCourse , AllCourses , Links , Solved);
            if (Action == 2) return;
        }

        else
        {
            cout << "Enter an assignment to submit : \n";
            int Choice = InputValidation (Assignments.size());
            string ChosenAssignment = Assignments[Choice - 1];
            string asscor = ChosenAssignment + ChosenCourse;
            while (Solved[asscor].find(Id) != Solved[asscor].end())
            {
                cout << "You have submitted this assignment , submit another one\n";
                Choice = InputValidation (Assignments.size());
                ChosenAssignment = Assignments[Choice - 1];
                asscor = ChosenAssignment + ChosenCourse;
            }
            SubmitAssignment(ChosenCourse , ChosenAssignment , AllCourses , Links , Solved);
        }
    }
    if (Action == 2) Actions(ChosenCourse , AllCourses , Links , Solved);
    if (Action == 3) return;
}
void Student :: SubmitAssignment (const string &ChosenCourse , const string &ChosenAssignment , vector <Course> &AllCourses , map <string,vector<string>> &Links , map <string , set <string>> &Solved)
{
    string Answer;
    cout << "Enter The Answer : \n";
    cin.ignore();
    getline (cin , Answer);
    ofstream AssignmentsFile("../Database/AssignmentsAnswers.txt",ios::app);
    AssignmentsFile << ChosenAssignment << '|' << ChosenCourse << '|' << GetId() << '|'<< Answer << '\n';
    AssignmentsFile.close();
    cout << "Submitted Successfully! Exit to confirm submission \n";
    cout << "1.Back to the last page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) Actions(ChosenCourse , AllCourses , Links , Solved);
    if (Action == 2) return;
}
