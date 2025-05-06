#include <bits/stdc++.h>
using namespace std;
struct student
{
    string f_name ; string l_name ;
    int id = 0 ;
    double marks[4] = {0,0,0,0} ;
    double Total_Marks = 0 ;
    double GPA = 0 ;
}; 
void Take_Input( student a[] , int size )
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Enter ( Frist Name , Last Name , ID ) For Student #" << i+1 << " : " ;
        cin >> a[i].f_name >> a[i].l_name >> a[i].id  ;
        cout << "Enter Student " << i+1 << " ( Mark < 100 ) 4 Marks : " ;
        for(int j = 0 ; j < 4 ; j++)
        {
            cin >> a[i].marks[j] ; 
            a[i].Total_Marks += a[i].marks[j] ;
        }
        cout << endl ;
    }
}
void Output( student a[] , int size )
{
    long double sum_ave = 0 ;
    long double sum_per = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        double Average = a[i].Total_Marks / 4 ;
        double percentage = ( a[i].Total_Marks / 400 ) * 100 ;
        sum_ave += Average ; sum_per += percentage ;
        cout << "Name : " << a[i].f_name << "  " << a[i].l_name << endl ;
        cout << "ID : " << a[i].id << endl ;
        cout << "Total Marks : " << a[i].Total_Marks << endl ;
        cout << "Average : " << fixed << setprecision(2) << Average << endl ; 
        cout << "Percentage : " << fixed << setprecision(2) << percentage << endl ;
        cout << endl ;
    }
    long double A_Average = sum_ave / size ;
    cout << "Average For All Class : " << fixed << setprecision(2) << A_Average << endl ;
    long double A_percentage = sum_per / size ;
    cout << "Average Percentage For All Class : " << fixed << setprecision(2) << A_percentage<< endl ;
}
void GPA_Calc( student a[] , int size , int id )
{
    for(int i = 0 ; i < size ; i++)
    {
        if ( a[i].id == id )
        {
            a[i].GPA = (a[i].Total_Marks+a[i].Total_Marks*0.10)/200;
            cout << a[i].f_name << " " << a[i].l_name << " GPA = " << a[i].GPA <<endl;
            break;
        }
    }
}
int main ()
{
    int num ;
    cout << " Enter The Number Of Students : " ; cin >> num ;
    student s[num] ; Take_Input( s , num ) ; Output( s , num ) ;
    bool flag = 0 ;
    cout << " Do You Want To Calc GPA For A Specific Student?  Answer (0 or 1) : " ; cin >> flag ;
    if ( flag == 1 )
    {
        int id = 0 ;
        cout << "Enter Student ID : " ; cin >> id ;
        GPA_Calc( s , num , id ) ;
    }
    else return 0 ;
    int end = 0 ;
    cout<<"Press 0 To End........"; cin >> end ; return 0 ;
}