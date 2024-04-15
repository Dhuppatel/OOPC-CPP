// this program is created for store and retrieve CHARUSAT employee details.
// created on
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
    static float avgExperince;

protected:
    void getdata() // function to get employee details from user
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

    void putdata() const // function to print employee details
    {
        cout << endl
             << "Name           :" << empName << endl;
        cout << "Qualification  :" << empQuali << endl;
        cout << "Experience     :" << empExp << " years" << endl;
        cout << "Contact Number :" << empMobile << endl;
    }
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
    static void displayAvgExperince(int numofemployee)  // Function to display average experience of employees
    {
        avgExperince /= numofemployee;
        cout << "Average experince of employees is " << avgExperince;
    }
};
class TeachingEmployee : public employee
{
    string designation;
    string specialization;
    string payscale;

public:
    void gettempdata()    // Function to get details of teaching employee
    {
        getdata();
        cout << "Enter Designation             :";
        fflush(stdin);
        getline(cin, designation);

        cout << "Enter Specialization          :";
        getline(cin, specialization);
        cout << "Enter Pay Scale               :";
        getline(cin, payscale);
    }
    void puttempdata()    // Function to print details of teaching employee
    {
        putdata();
        cout << "Designation    :" << designation<<endl;
        cout << "specialization :" << specialization<<endl;
        cout << "Pay scale      :" << payscale<<endl;
    }
    int searchtemp(int id)    // Function to search teaching employee by ID
    {
        if (searchemp(id))
        {
            puttempdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
class NonTeachingEmployee : public employee
{
    int salary;

public:
    void getntempdata()    // Function to get details of non-teaching employee
    {
        getdata();
        cout << "Enter salary                  :";
        cin >> salary;
    }
    void putntempdata()    // Function to print details of non-teaching employee
    {
        putdata();
        cout << "salary         :" << salary<<endl;
    }
    int searchntemp(int id)    // Function to search non-teaching employee by ID
    {
        if (searchemp(id))
        {
            putntempdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
float employee::avgExperince = 0;

int main()
{
    TeachingEmployee T[500];
    NonTeachingEmployee NT[500];

    int Teaching_employee;
    int NonTeaching_employee;
    int id;

    cout << "Enter the Number of Teaching employees:";
    cin >> Teaching_employee;

    cout << "Now Enter details of " << Teaching_employee << " employees :" << endl;

    for (int i = 0; i < Teaching_employee; i++) // For loop for input employee details
    {
        cout << "Enter details of employee " << i + 1 << " :" << endl;
        T[i].gettempdata();
    }
    cout << "Enter the Number of Non Teaching employees:";
    cin >> NonTeaching_employee;
    
    int totalemp = NonTeaching_employee + Teaching_employee;

    cout << "Now Enter details of " << NonTeaching_employee << " employees :" << endl;

    for (int i = 0; i < NonTeaching_employee; i++) // For loop for input employee details
    {
        cout << "Enter details of employee " << i + 1 << " :" << endl;
        NT[i].getntempdata();
    }

    int choice;
ch:
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
            for (int i = 0; i < NonTeaching_employee; i++)
            {

                flag = NT[i].searchntemp(id);
                if (flag == 1)
                {

                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 0)
            {
                for (int i = 0; i < Teaching_employee; i++)
                {

                    flag = T[i].searchtemp(id);
                    if (flag == 1)
                    {

                        
                        break;
                    }
                }
            }
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

        employee::displayAvgExperince(totalemp);
    break;
    default:
        cout << "Not valid choice.........";
        goto ch;
    }
    return 0;
}
