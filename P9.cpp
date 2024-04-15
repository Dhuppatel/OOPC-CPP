#include<bits/stdc++.h>
using namespace std;
class milimeter;
class centimeter{
    double cm;
 public:
    centimeter()
    {}
    centimeter(milimeter &m);  // Constructor to convert milimeter to centimeter
    void getdata(){
        cout<<"Enter mesurement in cm :";
        cin>>cm;
    }
    double putcm() //Method for returning value of cm
    {
        return cm;
    }
    void putdata(){  // Method to display cm

        cout<<"Mesurement in cm :"<<cm;
    }
    
};
class milimeter{
    
     double mm;
 public:
    milimeter(){}
    milimeter(centimeter &);   // Constructor to convert centimeter to milimeter
    void getdata(){
        cout<<"Enter mesurement in mm :";
        cin>>mm;
    }
    double putmm()  //Method that returns mm 
    {
        return mm;
    }
    void putdata()  //Method to display mm
    {
        cout<<"Mesurement in mm :"<<mm;
    }
};
centimeter::centimeter(milimeter &m)// Constructor to convert milimeter to centimeter
{
    cm=(double)m.putmm()/10.00;
}
milimeter::milimeter(centimeter &n)// Constructor to convert centimeter to milimeter
{
    mm=(double)n.putcm()*10.0;
}
int main()
{   
    centimeter ocm;
    milimeter omm;
    int choice;
    cout<<"Enter 1: mm to cm converter"<<endl;
    cout<<"Enter 2: cm to mm converter"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        omm.getdata();
        ocm=omm;
        ocm.putdata();
        break;
    case 2:
        ocm.getdata();
        omm=ocm;
        omm.putdata();
    default:
        break;
    }
    
    return 0;
}