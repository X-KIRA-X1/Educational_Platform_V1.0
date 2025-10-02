#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "System.h"
int InputValidation (int Range);
string ValidMail()
{
    cout << "Enter your mail :\n";
    string Mail; cin >> Mail;
    regex MailPattern(".{1,}@gmail\\.com$");
    while(!regex_match (Mail , MailPattern))
    {
        cout<<"Invalid form for mail\n";
        cout<<"The form must be like ""(blabla@gmail.com)"" , Please try again\n";
        cout << "Enter your mail :\n";
        cin >> Mail;
    }
    return Mail;
}
string ValidId()
{
    cout << "Enter Your Id : \n";
    regex IdPattern("^24140\\d{2}[1-9]$");
    string Id; cin >> Id;
    while (!regex_match(Id , IdPattern))
    {
        cout<<"Invalid form for Id\n";
        cout<<"The form must start with ""(24140)"" , Please try again\n";
        cin >> Id;
    }
    return Id;
}
void System :: LoadData()
{
    ifstream StudentsFile("../Database/Students.txt");
    ifstream DoctorsFile("../Database/Doctors.txt");
    ifstream CoursesFile("../Database/Courses.txt");
    ifstream AssignmentsFile("../Database/AssignmentsAnswers.txt");
    ifstream LecturesFile("../Database/Lectures.txt");
    if (!StudentsFile.is_open() || !DoctorsFile.is_open() || !CoursesFile.is_open() || !AssignmentsFile.is_open() || !LecturesFile.is_open()) {
        cerr << "Error opening one or more of the files\n";
        return ;
    }
    string StudentLine;
    while (getline(StudentsFile , StudentLine))
    {
        stringstream input(StudentLine);
        string name;
        getline(input , name , '|');

        string id;
        getline(input , id , '|');

        string mail;
        getline(input , mail , '|');

        string password;
        getline(input , password , '|');

        string coursess;
        getline(input , coursess);

        vector <string> courses;
        string course;
        stringstream courseinput(coursess);
        while(courseinput >> course) courses.push_back(course);

        Student student = Student (name , id , mail , password , courses);
        Students[mail] = student;
    }

    string DoctorLine;
    while (getline(DoctorsFile , DoctorLine))
    {
        stringstream input(DoctorLine);
        string name;
        getline(input ,name , '|');
        string mail;
        getline(input ,mail , '|');
        string password;
        getline(input ,password , '|');

        string coursess;
        getline(input , coursess);

        vector <string> courses;
        string course;
        stringstream courseinput(coursess);
        while(courseinput >> course) courses.push_back(course);
        Doctor doctor = Doctor(name , mail , password , courses);
        Doctors[mail] = doctor;
    }

    string AssignmentLine;
    while (getline(AssignmentsFile , AssignmentLine))
    {
        stringstream input(AssignmentLine);
        string title;
        getline(input , title , '|');

        string course;
        getline(input , course , '|');
        string asscor =  title + course;


        string id;
        getline(input , id , '|');

        string answer;
        getline(input , answer);

        AssignmentAnswer assignment = AssignmentAnswer(title , course , id , answer);
        AssignmentsAnswers.push_back(assignment);
        Solved[asscor].insert(id);
    }

    string CourseLine;
    while (getline(CoursesFile , CourseLine))
    {
        stringstream input(CourseLine);
        string title;
        getline(input , title , '|');

        string doctorname;
        getline(input , doctorname , '|');

        string doctormail;
        getline(input , doctormail , '|');

        vector <string> studentid;
        string ids;
        getline(input , ids , '|');
        stringstream inputid(ids);
        string id;
        while (getline(inputid , id , '.')) studentid.push_back(id);

        vector <string> allassignments;
        string assignments;
        getline(input , assignments);
        stringstream inputassignment(assignments);
        string assignment;
        while (getline(inputassignment , assignment , '.')) allassignments.push_back(assignment);

        Course course = Course (title , doctorname , doctormail , studentid , allassignments);
        Courses.push_back(course);
    }

    string LectureLine;
    while (getline(LecturesFile , LectureLine))
    {
        stringstream input(LectureLine);
        string Course; vector <string> Links;
        getline (input , Course , '|');
        string LinksLine; getline(input , LinksLine);
        stringstream LinksInput(LinksLine);
        string Link;
        while (LinksInput >> Link) Links.push_back(Link);
        Lectures[Course] = Links;
    }

}
void System :: Startup()
{
    LoadData();
    cout << "             Educational Platform V 1.0             " << "\n\n";
    cout << "1.Signup \n2.Login \n3.Exit\n";
    int Choice = InputValidation(3);
    if (Choice == 1) SignUp();
    else if(Choice == 2) Login();
    else if(Choice == 3) return;
}
void System :: SignUp()
{
    cout <<"1.Doctor\n2.Student\n";
    int Choice = InputValidation(2);
    if (Choice == 1) cout << "Contact us to create an account \n";
    if (Choice == 2)  StudentSignup();
}
void System :: StudentSignup()
{
    cout << "Enter your name : \n";
    cin.ignore();
    string Name; getline(cin , Name);
    string Id = ValidId();
    string Mail = ValidMail();
    cout << "Enter a password : \n";
    string Password; cin >> Password;
    vector <string> Coursess = {"CS" , "Logic" , "Math" , "DataStructure" , "Programming"};
    vector <string> ChosenCourses;
    cout << "Select Your Courses : \n";
    int CourseNum = 1;
    for (string Course : Coursess)
    {
        cout << CourseNum++ << '.' << Course << '\n';
    }
    cout << "Enter the number of courses you want to enroll in : \n";
    int NumberOfCourses = InputValidation(5);
    int Num = 0;
    vector <string> Nums = {"first" , "second" , "third" , "forth" , "fifth"};
    while (NumberOfCourses--)
    {
        cout << "Enter the " << Nums[Num++] << " course : \n";
        int Course ; cin >> Course ;
        ChosenCourses.push_back(Coursess[Course-1]);
    }
    ofstream StudentFile ("../Database/Students.txt" , ios :: app);
    StudentFile << Name << '|' << Id << '|' << Mail << '|' << Password << '|';
    for (string Course : ChosenCourses) StudentFile << Course << " ";
    StudentFile << "\n";
    StudentFile.close();
    cout << "Account created successfully! Try to login again\n";
    set <string> ChosenCoursesSet (ChosenCourses.begin() , ChosenCourses.end());
    ifstream ICoursesFile("../Database/Courses.txt");
    vector <string> lines;
    string line;
    while (getline(ICoursesFile , line)) lines.push_back(line);
    for (int i = 0 ; i < lines.size() ; i++)
    {
        stringstream input(lines[i]);
        string Course; getline (input , Course , '|');
        if (ChosenCoursesSet.find(Course) != ChosenCoursesSet.end())
        {
            int Pointer = lines[i].size() - 1;
            while (lines[i][Pointer] != '|') Pointer--;
            lines[i].insert(Pointer , Id + '.');
        }
    }
    ofstream OCoursesFile("../Database/Courses.txt");
    for (const string &Oneline : lines) OCoursesFile << Oneline << '\n';
    OCoursesFile.close();
}
void System :: Login()
{
    cout << "1.Doctor\n2.Student\n";
    int Choice = InputValidation(2);
    if (Choice == 1) DoctorLogin(AssignmentsAnswers);
    else if (Choice == 2) StudentLogin();
}
void System :: DoctorLogin(vector <AssignmentAnswer> AssignmentsAnswers)
{
    cout << "Please enter your mail\n";
    string mail; cin >> mail;

    cout << "Please enter your password\n";
    string password; cin >> password;
    if (Doctors.find(mail) == Doctors.end() or Doctors[mail].GetPassword() != password)
    {
        cout << "Invalid credentials!\n";
        cout << "1.Try again\n2.Exit\n";
        int Choice = InputValidation(2);
        if (Choice == 1)
        {
            DoctorLogin(AssignmentsAnswers);
            return;
        }
        else if (Choice == 2) return;
    }
    Doctors[mail].DoctorPortal(AssignmentsAnswers);
}
void System :: StudentLogin()
{
    cout << "Please enter your mail\n";
    string Mail; cin >> Mail;

    cout << "Please enter your password\n";
    string Password; cin >> Password;
    while (Students.find(Mail) == Students.end() or Students[Mail].GetPassword() != Password)
    {
        cout << "Invalid credentials!\n";
        cout << "1.Try again\n2.Exit\n";
        int Choice = InputValidation(2);
        if (Choice == 1)
        {
            StudentLogin();
            return;
        }
        else if (Choice == 2) return;
    }
    Students[Mail].StudentPortal(Courses , Lectures , Solved);
}
void System :: Debug()
{
    cout << "        Doctors        \n";
    for (auto Doctor : Doctors) Doctor.second.Print();
    cout << "\n";

    cout << "        Students        \n";
    for (auto Student : Students) Student.second.Print();
    cout << "\n";

    cout << "        Courses        \n";
    for (auto Course : Courses) Course.Print();
    cout << "\n";

    cout << "        AssignmentsAnswers        \n";
    for (auto AssignmentAnswer : AssignmentsAnswers) AssignmentAnswer.Print();
    cout << "\n";
}
