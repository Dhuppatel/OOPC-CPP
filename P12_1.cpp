#include <bits/stdc++.h>
using namespace std;
class result;
class Student
{
    char stu_id[8];//char array to store student id
    string stu_name; // without space
    short int semester;

public:
    void getdata_stu()   // Method to get student data from user input
    {
        cout << "Enter student id:";
        cin.getline(stu_id, 8);
        fflush(stdin);  // Clear input buffer
        cout << "Enter student name:";
        cin >> stu_name;
        fflush(stdin);
        cout << "Enter semester:";
        cin >> semester;
    }
    void putdata_stu()    // Method to display student data
    {
         cout<<"Student Id   : "<<stu_id<<endl;
    cout<<"Student Name : "<<stu_name<<endl;
    cout<<"Semester     : "<<semester<<endl;
    }

    void getdata_result(result &);    // Method to get result data from user input
    void putdata_result(result &);    // Method to display result data
};
class result{
    char stu_id[10];
    string stu_name;
    int sem;
    string sub_name[3];
    int th_mark[3];
    int pr_mark[3];
    string th_grade[3];
    string pr_grade[3];
    int th_gradep[3];
    int pr_gradep[3];
    float SGPA;
    int sum=0,credit=3, total_credit=3+3+3+3+3+3;
 public:
    friend void Student::getdata_result(result &);
    friend void Student::putdata_result(result &);

};
// Method to get result data from user input
void Student::getdata_result(result &r){
    for(int i=0; i<3; i++)
    {
        cout<<"enter name of subject "<<i+1<<":";
        fflush(stdin);
        getline(cin,r.sub_name[i]);
    }
     for(int i=0; i<3; i++)
    {
        cout<<"Enter theory marks of "<<r.sub_name[i]<<" :";
        cin>>r.th_mark[i];
        cout<<endl<<"Enter practical marks of "<<r.sub_name[i]<<" :";
        cin>>r.pr_mark[i];
    }
}
// Method to display result data
void Student::putdata_result(result &r){
    // Calculate grades and grade points for each subject
     for(int i=0; i<3; i++)
    {

        if(r.th_mark[i]>=80)
        {
            r.th_grade[i]="AA";
            r.th_gradep[i]=10;
        }
        if(r.pr_mark[i]>=80)
        {
            r.pr_grade[i]="AA";
            r.pr_gradep[i]=10;
        }
        if(r.th_mark[i]<80 && r.th_mark[i]>=73)
        {
            r.th_grade[i]="AB";
            r.th_gradep[i]=9;
        }
        if(r.pr_mark[i]<80 && r.pr_mark[i]>=73)
        {
            r.pr_grade[i]="AB";
            r.pr_gradep[i]=9;
        }
        if(r.th_mark[i]<73 && r.th_mark[i]>=66)
        {
            r.th_grade[i]="BB";
            r.th_gradep[i]=8;
        }
        if(r.pr_mark[i]<73 && r.pr_mark[i]>=66)
        {
            r.pr_grade[i]="BB";
            r.pr_gradep[i]=8;
        }
        if(r.th_mark[i]<66 && r.th_mark[i]>=60)
        {
            r.th_grade[i]="BC";
            r.th_gradep[i]=7;
        }
        if(r.pr_mark[i]<66 && r.pr_mark[i]>=60)
        {
            r.pr_grade[i]="BC";
            r.pr_gradep[i]=7;
        }
        if(r.th_mark[i]<60 && r.th_mark[i]>=55)
        {
            r.th_grade[i]="CC";
            r.th_gradep[i]=6;
        }
        if(r.pr_mark[i]<60 && r.pr_mark[i]>=55)
        {
            r.pr_grade[i]="CC";
            r.pr_gradep[i]=6;
        }
        if(r.th_mark[i]<55 && r.th_mark[i]>=50)
        {
            r.th_grade[i]="CD";
            r.th_gradep[i]=5;
        }
        if(r.pr_mark[i]<55 && r.pr_mark[i]>=50)
        {
            r.pr_grade[i]="CD";
            r.pr_gradep[i]=5;
        }
        if(r.th_mark[i]<50 && r.th_mark[i]>=45)
        {
            r.th_grade[i]="DD";
            r.th_gradep[i]=4;
        }
        if(r.pr_mark[i]<50 && r.pr_mark[i]>=45)
        {
            r.pr_grade[i]="DD";
            r.pr_gradep[i]=4;
        }
        if(r.th_mark[i]<45)
        {
            r.th_grade[i]="FF";
            r.th_gradep[i]=0;
        }
        if(r.pr_mark[i]<45)
        {
            r.pr_grade[i]="FF";
            r.pr_gradep[i]=0;
        }
    }
    //calculation for sgpa
    for(int i=0; i<3; i++)
    {
        r.sum+=r.credit*r.th_gradep[i] + r.credit*r.pr_gradep[i];
    }
    r.SGPA=(float)r.sum/r.total_credit;

    cout<<setw(58)<<"Theory    practical"<<endl;
//display result
    for(int i=0; i<3; i++)
    {
        cout<<left<<setw(29)<<r.sub_name[i]<<right<<setw(15)<<r.th_grade[i]<<"          "<<r.pr_grade[i]<<endl<<endl;
    }

    cout<<"SGPA :"<<fixed<<setprecision(2)<<r.SGPA;
}
int main()
{
    Student s;
    result r;
    s.getdata_stu();
    s.getdata_result(r);
    system("CLS");  // Clear console screen
    s.putdata_stu();// Display student data
    s.putdata_result(r);// Display result data

    return 0;
}