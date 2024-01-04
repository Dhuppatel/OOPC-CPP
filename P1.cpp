//this program is created for charusat marksheet generator
//created on 04/01/2024
//created by Dhup patel
#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main()
{
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


    cout<<"Enter student id:";
    cin.getline(stu_id,10);
    fflush(stdin);
    cout<<"Enter student name:";
    cin>>stu_name;
    fflush(stdin);
    cout<<"Enter semester:";
    cin>>sem;

    for(int i=0; i<3; i++)
    {
        cout<<"enter name of subject "<<i+1<<":";
        fflush(stdin);
        getline(cin,sub_name[i]);
    }

    for(int i=0; i<3; i++)
    {
        cout<<"Enter theory marks of "<<sub_name[i]<<" :";
        cin>>th_mark[i];
        cout<<endl<<"Enter practical marks of "<<sub_name[i]<<" :";
        cin>>pr_mark[i];
    }
    for(int i=0; i<3; i++)
    {

        if(th_mark[i]>=80)
        {
            th_grade[i]="AA";
            th_gradep[i]=10;
        }
        if(pr_mark[i]>=80)
        {
            pr_grade[i]="AA";
            pr_gradep[i]=10;
        }
        if(th_mark[i]<80 && th_mark[i]>=73)
        {
            th_grade[i]="AB";
            th_gradep[i]=9;
        }
        if(pr_mark[i]<80 && pr_mark[i]>=73)
        {
            pr_grade[i]="AB";
            pr_gradep[i]=9;
        }
        if(th_mark[i]<73 && th_mark[i]>=66)
        {
            th_grade[i]="BB";
            th_gradep[i]=8;
        }
        if(pr_mark[i]<73 && pr_mark[i]>=66)
        {
            pr_grade[i]="BB";
            pr_gradep[i]=8;
        }
        if(th_mark[i]<66 && th_mark[i]>=60)
        {
            th_grade[i]="BC";
            th_gradep[i]=7;
        }
        if(pr_mark[i]<66 && pr_mark[i]>=60)
        {
            pr_grade[i]="BC";
            pr_gradep[i]=7;
        }
        if(th_mark[i]<60 && th_mark[i]>=55)
        {
            th_grade[i]="CC";
            th_gradep[i]=6;
        }
        if(pr_mark[i]<60 && pr_mark[i]>=55)
        {
            pr_grade[i]="CC";
            pr_gradep[i]=6;
        }
        if(th_mark[i]<55 && th_mark[i]>=50)
        {
            th_grade[i]="CD";
            th_gradep[i]=5;
        }
        if(pr_mark[i]<55 && pr_mark[i]>=50)
        {
            pr_grade[i]="CD";
            pr_gradep[i]=5;
        }
        if(th_mark[i]<50 && th_mark[i]>=45)
        {
            th_grade[i]="DD";
            th_gradep[i]=4;
        }
        if(pr_mark[i]<50 && pr_mark[i]>=45)
        {
            pr_grade[i]="DD";
            pr_gradep[i]=4;
        }
        if(th_mark[i]<45)
        {
            th_grade[i]="FF";
            th_gradep[i]=0;
        }
        if(pr_mark[i]<45)
        {
            pr_grade[i]="FF";
            pr_gradep[i]=0;
        }
    }
    for(int i=0; i<3; i++)
    {
        sum+=credit*th_gradep[i] + credit*pr_gradep[i];
    }
    SGPA=(float)sum/total_credit;

    system("CLS");
    cout<<"Student ID   :"<<stu_id<<endl;
    cout<<"Student Name :"<<stu_name<<endl;
    cout<<"Semester     :"<<sem<<endl;
    cout<<setw(58)<<"Theory    practical"<<endl;

    for(int i=0; i<3; i++)
    {
        cout<<left<<setw(29)<<sub_name[i]<<right<<setw(15)<<th_grade[i]<<"          "<<pr_grade[i]<<endl<<endl;
    }

    cout<<"SGPA :"<<fixed<<setprecision(2)<<SGPA;
return 0;
}
