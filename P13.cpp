// this program is created to Update the CHARUSAT employee system (practical 8) as per given class diagram
// created by Dhup patel
#include <iostream>
#include <stdlib.h>
using namespace std;

class employee
{
private:
    int empId;
    string empName;
    string empQuali;
    float empExp;
    long long int empMobile;
    static float avgExperince;// Static variable to store average experience

protected:
    void getdata() // Method to get employee details from user
    {
        cout << "Employee Id :";
        cin >> empId;
        cout << "Enter employee name           :";
        cin >> empName;
        fflush(stdin);
        cout << "Enter employee qualification  :";
        getline(cin, empQuali);
        fflush(stdin);
        cout << "Enter employee Experience     :";
        cin >> empExp;
        avgExperince += empExp;

        cout << "ENter employee Contact Number :";
        cin >> empMobile;
    }

    void putdata() const // Method to print employee details
    {
        cout << endl
             << "Name           :" << empName << endl;
        cout << "Qualification  :" << empQuali << endl;
        cout << "Experience     :" << empExp << " years" << endl;
        cout << "Contact Number :" << empMobile << endl;
    }
        // Method to search for an employee by ID
    int searchemp(int id) const
    {
        if (id == empId)
        {

            return 1;
        }
        else
        {
            return 0;
        }
    }
 public:
     // Static method to display average experience of employees
    static void displayAvgExperince(int numofemployee)
    {
        avgExperince /= numofemployee;
        cout << "Average experince of employees is " << avgExperince;
    }
};
// Declaration of class TeachingEmployee inheriting from employee
class TeachingEmployee : public employee
{
    string designation;
    string specialization;
    string payscale;

public:
    void getdata()    // Method to get teaching employee details from user
    {
        employee::getdata();
        cout << "Enter Designation             :";
        fflush(stdin);
        getline(cin, designation);

        cout << "Enter Specialization          :";
        getline(cin, specialization);
        cout << "Enter Pay Scale               :";
        getline(cin, payscale);
    }
    void putdata()    // Method to print teaching employee details
    {
        employee::putdata();
        cout << "Designation    :" << designation<<endl;
        cout << "specialization :" << specialization<<endl;
        cout << "Pay scale      :" << payscale<<endl;
    }
        // Method to search for a teaching employee by ID
    int searchemp(int id)
    {
        if (employee::searchemp(id))
        {
            putdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
// Declaration of class NonTeachingEmployee inheriting from employee
class NonTeachingEmployee : public employee
{
    int salary;

public:
    void getdata()    // Method to get non-teaching employee details from user
    {
        employee::getdata();
        cout << "Enter salary                  :";
        cin >> salary;
    }
    void putdata()    // Method to print non-teaching employee details
    {
        employee::putdata();
        cout << "salary         :" << salary<<endl;
    }
        // Method to search for a non-teaching employee by ID
    int searchemp(int id)
    {
        if (employee::searchemp(id))
        {
            putdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
// Definition of static member variable avgExperince
float employee::avgExperince = 0;

int main()
{
    // Arrays to store teaching and non-teaching employees
    TeachingEmployee T[500];
    NonTeachingEmployee NT[500];

    int Teaching_employee;
    int NonTeaching_employee;
    int id;

    // Get number of teaching employees and their details

    cout << "Enter the Number of Teaching employees:";
    cin >> Teaching_employee;

    cout << "Now Enter details of " << Teaching_employee << " employees :" << endl;

    for (int i = 0; i < Teaching_employee; i++) // For loop for input employee details
    {
        cout << "Enter details of employee " << i + 1 << " :" << endl;
        T[i].getdata();
    }
    // Get number of non-teaching employees and their details
    cout << "Enter the Number of Non Teaching employees:";
    cin >> NonTeaching_employee;
    
    int totalemp = NonTeaching_employee + Teaching_employee;

    cout << "Now Enter details of " << NonTeaching_employee << " employees :" << endl;

    for (int i = 0; i < NonTeaching_employee; i++) // For loop for input employee details
    {
        cout << "Enter details of employee " << i + 1 << " :" << endl;
        NT[i].getdata();
    }

    int choice;
ch:
    // User menu
    cout << "Press 1 to retrive employee details and 2 for average experince :";
    cin >> choice;

    switch (choice)
    {
    case 1:

        cout << "employee details::::::" << endl;

        // do-while loop for user to rertrive employee details
        do
        {
            cout << "Enter employee id :";
            cin >> id;
            int flag, flag2 = 0;
            
            // Search for non-teaching employees by ID
            for (int i = 0; i < NonTeaching_employee; i++)
            {

                flag = NT[i].searchemp(id);
                if (flag == 1)
                {

                    flag2 = 1;
                    break;
                }
            }
                 // If not found in non-teaching, search in teaching employees
            if (flag2 == 0)
            {
                for (int i = 0; i < Teaching_employee; i++)
                {

                    flag = T[i].searchemp(id);
                    if (flag == 1)
                    {

                        
                        break;
                    }
                }
            }
            // If employee not found, display error message
            if (flag == 0)
            {
                cout << "******************************************" << endl
                     << endl;
                cout << "  ERROR:ENTERED EMPLOYEE DOES NOT EXIST" << endl
                     << endl;
                cout << "******************************************" << endl;
            }
            char ch;
            cout << "press Y to get another employee detail, press N to exit :";
            cin >> ch;
        A:
        // Validate user choice
            if (ch == 'N' || ch == 'n')
            {
                exit(0);
            }
            else if (ch == 'Y' || ch == 'y')
            {
                continue;
            }
            else
            {
                cout << "Enter valid option......" << endl;
                goto A;
            }
        } while (1);
        break;
    case 2:
     // Display average experience of employees
        employee::displayAvgExperince(totalemp);
    break;
    default:
        cout << "Not valid choice.........";
        goto ch;
    }
    return 0;
}
