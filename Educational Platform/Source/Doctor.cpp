#include <iostream>
#include <fstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include "Doctor.h"
#include "System.h"
int InputValidation (int Range);
bool comp (AssignmentAnswer Answer1 , AssignmentAnswer Answer2) {return Answer1 < Answer2;}
void Doctor :: DoctorPortal(vector <AssignmentAnswer> &AssignmentsAnswers)
{
    int CourseNum = 1;
    for (string Course : Courses) cout << CourseNum++ << "." << Course << "\n";
    cout << "Select a course : \n";
    int Choice = InputValidation(Courses.size());
    string ChosenCourse = Courses[Choice - 1];
    cout << "1.Add an assignment\n2.Show assignments answers\n3.Add lecture link\n4.Show grades\n";
    int Action = InputValidation(4);
    if (Action == 1) AddAssignment(ChosenCourse , AssignmentsAnswers);
    if (Action == 2) ShowAssignmentsAnswers(ChosenCourse , AssignmentsAnswers);
    if (Action == 3) AddLectureLink(ChosenCourse , AssignmentsAnswers);
    if (Action == 4) ShowGrades(ChosenCourse , AssignmentsAnswers);

}
void Doctor :: AddAssignment(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers)
{
    ifstream ICoursesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Courses.txt");
    vector <string> lines;
    string line;
    while (getline (ICoursesFile , line)) lines.push_back(line);
    for (int i = 0 ; i < lines.size() ; i++)
    {
        stringstream input(lines[i]);
        string Course;
        getline (input , Course , '|');
        if (Course == ChosenCourse)
        {
            cout << "Enter the assignment name : \n";
            string AssignmentName; cin >> AssignmentName;
            lines[i] += "." + AssignmentName;
            break;
        }
    }
    ofstream OCoursesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Courses.txt");
    for (string line : lines) OCoursesFile << line << "\n";
    cout << "Assignment has been added successfully!";
    cout << "1.Back to the last page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) DoctorPortal(AssignmentsAnswers);
    if (Action == 2) return;
}
void Doctor :: ShowAssignmentsAnswers(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers)
{
    vector <AssignmentAnswer> CourseAssignmentsAnswers;
    for (auto Answer : AssignmentsAnswers)
    {
        if (Answer.GetCourse() == ChosenCourse) CourseAssignmentsAnswers.push_back(Answer);
    }
    sort (CourseAssignmentsAnswers.begin() , CourseAssignmentsAnswers.end() , comp);
    int AnswerNum = 1;
    for (auto Answer : CourseAssignmentsAnswers)
    {
        cout << AnswerNum++ << ".Student (" << Answer.GetId() << ") answer to " << Answer.GetTitle() << " is : " << Answer.GetAnswer() << "\n";
    }
    cout << "\n1.Add grade\n2.Back to the last page\n3.Exit\n";
    int Action = InputValidation(3);
    if (Action == 1) AddGrade(ChosenCourse , CourseAssignmentsAnswers , AssignmentsAnswers);
    if (Action == 2) DoctorPortal(AssignmentsAnswers);
    if (Action == 3) return;
}
void Doctor :: AddGrade (string ChosenCourse , vector <AssignmentAnswer> &CourseAssignmentsAnswers , vector <AssignmentAnswer> &AssignmentsAnswers)
{
    cout << "Enter the answer number : \n";
    int Choice = InputValidation(CourseAssignmentsAnswers.size());
    ofstream GradesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Grades.txt" , ios :: app);
    cout << "Enter the Grade : \n";
    string Grade; cin >> Grade;
    GradesFile <<  ChosenCourse << '|'
               << CourseAssignmentsAnswers[Choice - 1].GetTitle() << '|'
               << CourseAssignmentsAnswers[Choice - 1].GetId() << '|'
               << Grade << "\n\n";
    cout << "Grade has been added successfully!\n";
    cout << "\n1.Back to the main page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) DoctorPortal(AssignmentsAnswers);
    if (Action == 2) return;
}
void Doctor :: AddLectureLink(string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers)
{
    ifstream ILecturesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Lectures.txt");
    vector <string> lines;
    string line;
    while (getline (ILecturesFile , line)) lines.push_back(line);
    for (int i = 0 ; i < lines.size() ; i++)
    {
        stringstream input(lines[i]);
        string Course;
        getline (input , Course , '|');
        if (Course == ChosenCourse)
        {
            cout << "Enter the link :\n";
            string Link ; cin >> Link;
            lines[i] += " " + Link;
            break;
        }
    }
    ofstream OLecturesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Lectures.txt");
    for (string line : lines) OLecturesFile << line << "\n";
    cout << "Link has been added successfully!\n";
    cout << "1.Back to the last page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) DoctorPortal(AssignmentsAnswers);
    if (Action == 2) return;
    //bug deleting all the lines in the file until exiting?
}
void Doctor :: ShowGrades (string ChosenCourse , vector <AssignmentAnswer> &AssignmentsAnswers)
{
    ifstream GradesFile("D:\\Projects\\Projects_Gits\\Educational Platform\\Database\\Grades.txt");
    map <string , vector <pair<string,string>>> AssignmentGrades;
    vector <string> lines;
    string line;
    while (getline(GradesFile , line)) lines.push_back(line);
    for (string OneLine : lines)
    {
        stringstream input(OneLine);
        string Course;
        getline (input , Course , '|');
        if (Course == ChosenCourse)
        {
            string Assignment;
            getline (input , Assignment , '|');
            string Id;
            getline (input , Id , '|');
            string Grade;
            getline (input , Grade);
            AssignmentGrades[Assignment].push_back({Id , Grade});
        }
    }
    for (auto AssignmentGrade : AssignmentGrades)
    {
        cout << AssignmentGrade.first << " : \n";
        for (auto P : AssignmentGrade.second)
        {
            cout << "Student Id (" << P.first << ") Grade : " << P.second << "\n";
        }
    }
    cout << "\n1.Back to the last page\n2.Exit\n";
    int Action = InputValidation(2);
    if (Action == 1) DoctorPortal(AssignmentsAnswers);
    if (Action == 2) return;
}
