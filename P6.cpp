//this program is created for store and retrieve CHARUSAT employee details.
//created on 18/01/2024
//created by Dhup patel
#include<iostream>
#include<stdlib.h>
using namespace std;

struct employee
{
private:
    int empId;
    string empName;
    string empQuali;
    float empExp;
    long long int empMobile;
    static float avgExperince;
public:
     

    void getdata()// function to get employee details from user
    {   
         cout<<"Employee Id :";
        cin>>empId;
        cout<<"Enter employee name           :";
        cin>>empName;
        fflush(stdin);
        cout<<"Enter employee qualification  :";
        getline(cin,empQuali);
        fflush(stdin);
        cout<<"Enter employee Experience     :";
        cin>>empExp;
        avgExperince+=empExp;

        cout<<"ENter employee Contact Number :";
        cin>>empMobile;


    }
    int putdata(int id) const //function to print employee details 
    {
        if(id==empId)
        {
        cout<<endl<<"Name           :"<<empName<<endl;
        cout<<"Qualification  :"<<empQuali<<endl;
        cout<<"Experience     :"<<empExp<<" years"<<endl;
        cout<<"Contact Number :"<<empMobile<<endl;
        return 1;
        }
        else
        {
            return 0;
        }
    }
    static void displayAvgExperince(int numofemployee)
    {
        avgExperince/=numofemployee;
        cout<<"Average experince of employees is "<<avgExperince;
    }
};

float employee::avgExperince=0;

int main()
{
    struct employee e[999];


    int number_of_employee;
    int id;

    cout<<"Enter the Number of employees:";
    cin>>number_of_employee;

    cout<<"Now Enter details of "<< number_of_employee<<" employees :"<<endl;


    for(int i=0;i<number_of_employee;i++)//For loop for input employee details
    {
        cout<<"Enter details of employee "<<i+1<<" :"<<endl;
        e[i].getdata();
    }
  
    int choice;
    ch:
        cout<<"Press 1 to retrive employee details and 2 for average experince";
        cin>>choice;
        if(choice<1 || choice>2)
        {
            cout<<"Not valid choice.........";
            goto ch; 
        }
    if(choice==1){


      cout<<"employee details::::::"<<endl;

       //do-while loop for user to rertrive employee details
     do
      {
        cout<<"Enter employee id :";
        cin>>id;
        int flag;
        for (int i = 0; i < number_of_employee; i++)
        {
            
            flag= e[i].putdata(id);
            if(flag==1)
                break;
        }
        if(flag==0)
        {
            cout<<"******************************************"<<endl<<endl;
            cout<<"  ERROR:ENTERED EMPLOYEE DOES NOT EXIST"<<endl<<endl;
            cout<<"******************************************"<<endl;
        }
        char ch;
        cout<<"press Y to get another employee detail, press N to exit :";
        cin>>ch;
       A:
            if(ch=='N' || ch=='n')
        {
            exit(0);
        }
        else if(ch=='Y' || ch=='y')
        {
            continue;
        }
        else{
            cout<<"Enter valid option......"<<endl;
            goto A;
        }
       }while(1);
    }
    else
    {
        employee::displayAvgExperince(number_of_employee);
    }
    return 0;
}
