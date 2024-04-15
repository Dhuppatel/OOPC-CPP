#include<bits/stdc++.h>
using namespace std;
class Employee{
    int years,months;
    float experience;
 public:
    Employee(){   // Default constructor to initialize experience to 0.00
        experience=0.00;
    }
    void getdata()      // Method to get employee's experience from user input
    {
        cout<<"Enter employee experience in years and months"<<endl;
        cout<<"Years:";
        cin>>years;
        cout<<"Months:";
        cin>>months; 
    }
    operator float()     // Conversion operator to convert Employee object to float representing total experience
    {   
        experience+=years;
        experience+=(months)/(float)12;
        return experience;

    }
};
int main()
{
    Employee e;
    e.getdata();
    float experience;
    experience=e;   // Implicitly call conversion operator to convert Employee object to float
    cout<<"Employee experience is :"<<experience;
    return 0;
}