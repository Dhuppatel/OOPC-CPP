// this program is createdto take floating point number and assign to employee experience
// created by Dhup patel(23CE094)
#include <bits/stdc++.h>
using namespace std;
class employee
{
    int exp_years, exp_months;

public:
    employee() {}  //default constructor
    employee(float experience) // Parameterized constructor to initialize experience in years and months
    {
        int temp;
        exp_years = experience; // float is automatically converted to int
        temp = (experience - exp_years) * 100;

        exp_months = (temp * 12) / 100;
    }
    void putdata()    // Method to display employee's experience
    {
        cout << "Employees experience is " << exp_years << " years and " << exp_months << " moinths" << endl;
    }
};
int main()
{
    employee e;
    float experience;
    cout<<"Enter Employee Experience :";
    cin>>experience;  // Read experience from user
    e=experience;
    e.putdata();    // Display the employee's experience

    return 0;
}