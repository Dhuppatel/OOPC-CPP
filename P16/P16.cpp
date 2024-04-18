// this program is created for  car data management system for TATA motors..(using file)
// created by Dhup patel (23CE094)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
int number_of_cars;
void putcolums()
{
    cout << left << setw(10) << "Model" << setw(9) << "Fuel" << setw(10) << "price" << setw(12) << "mileage";
    cout << setw(16) << "Transmission" << setw(18) << "Tank Capacity" << setw(12) << "Seating" << setw(12) << "Airbags" << endl;
    cout << right << setw(25) << "(lakhs)" << setw(11) << "(km/L)" << setw(30) << "(Liters)" << setw(17) << "capacity" << endl;
}
class CAR
{

    string modelName;
    string fuelType;
    float price;
    float milage;
    string transmission;
    float tankCapacity;
    short int seat;
    string airbag;
    int temp;

public:
    void getdata(string model, string fuel, float Price, float Milage, string trnsmission, float tank, short int seating, string airbagg) // This function is used to input the details of a car.
    {
        modelName = model;
        fuelType = fuel;
        price = Price;
        milage = Milage;
        transmission = trnsmission;
        tankCapacity = tank;
        seat = seating;
        airbag = airbagg;
    }

    void putdata() // This function is used to display the details of a car.
    {
        cout << left << setw(10) << modelName << setw(9) << fuelType << setw(10) << price << setw(12) << milage
             << setw(16) << transmission << setw(18) << tankCapacity << setw(12) << seat << setw(12) << airbag;
    }
    void putdatabyname() // This function is used to display the details of a specific car model.
    {
        putcolums();
        putdata();
    }

    void printlist() // This function is used to display the name of a car in a list.
    {
        cout << modelName << "    ";
    }

    void putdatabyFuelType(string tempfueltype) // This function is used to display the details of cars with a specific fuel type.
    {

        if (fuelType == tempfueltype)
        {
            putdata();
        }
    }

    void putdatabyRange(int AffordablePrice) // This function is used to display the details of cars within a specific price range.
    {
        if (price <= AffordablePrice)
            putdata();
    }
};

int main()
{
    CAR cars[999];

    string s;              //Temp variables for giving aargument to getdata
    string model;
    string fuel;
    string tempFueltype;
    float price;
    float milage;
    string trnsmission;
    float tank;
    short int seating;
    string airbagg;
    char ch;


    ifstream file;                  //create an if stream object
    file.open("cardata.txt");       //open file cardata.txt
    if(!file)   //Error Handeling for file 
    {
        cout<<"file not found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }
    int itrator = 0;
    while (getline(file, s, ';'))    //while loop to get data from file and saving them into class CAR objects
    {
        stringstream ss(s);

        getline(ss, model, ',');

        getline(ss, fuel, ',');
        ss >> price>>ch>>milage>>ch;
        getline(ss,trnsmission,',');
        ss>>tank>>ch>>seating>>ch;
        getline(ss,airbagg);


        cars[itrator].getdata(model, fuel, price, milage, trnsmission, tank, seating, airbagg);
         itrator++;
    }
    file.close(); // close the file

menu: // to print the menu for user
    system("CLS");
    cout << setw(205)<<"~~~~~~~~~~~~~~~ WELCOME TO TATA MOTARS ~~~~~~~~~~~~~~~" << endl
         << endl;
    cout << "GET THE CAR DETAILS AS PER YOUR PREFERENCE ";
    cout << "(1)Model Name  (2)Fuel Type  (3)Price Range" << endl;
    int choice;
    cout << "Enter your choice :";
    fflush(stdin);

    cin >> choice;
    cout << "---------------------" << endl;
    switch (choice) // switch case to Call the appropriate function based on the user's choice
    {
    case 1: // case for retrive data by car model
        cout << "LIST OF TATA CARS" << endl;
        int choice2;
        for (int i = 0; i < itrator; i++)
        {
            cout << "(" << i + 1 << ")";
            cars[i].printlist();
        }
        cout << endl
             << "Enter your choice :";
        fflush(stdin);
        cin >> choice2;

        putcolums();
        cars[choice2 - 1].putdata();
        break;
    case 2: // case for retrive data by  fuel type
        int secondChoice;
        cout << "TATA MOTARS ARE AVAILABLE WITH FUEL OPTIONS" << endl;
        cout << "(1)Petrol (2)Diesel (3)CNG (4)Electric " << endl;
        cout << "Enter Your Fuel Preference :";
    d:
        cin >> secondChoice;
        if (secondChoice == 1)
            tempFueltype = "Petrol";
        else if (secondChoice == 2)
            tempFueltype = "Diesel";
        else if (secondChoice == 3)
            tempFueltype = "CNG";
        else if (secondChoice == 4)
            tempFueltype = "Electric";

        if (secondChoice > 4 || secondChoice < 1)
        {
            cout << "please enter an valid choice :";
            goto d;
        }

        putcolums();
        for (int i = 0; i < itrator; i++)
        {
            cars[i].putdatabyFuelType(tempFueltype);
            cout << endl;
        }
        break;
    case 3: // case for get data by price range
        int AffordablePrice;
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS :";
        cin >> AffordablePrice;

        putcolums();

        for (int i = 0; i < itrator; i++)
        {
            cars[i].putdatabyRange(AffordablePrice);
            cout << endl;
        }

    default:
        break;
    }
    int choice3;
    cout << endl
         << "press '1' to go to main-menu and press 0 to Exit  :";
    cin >> choice3;
    if (choice3 == 0)
        exit(0);
    else
        goto menu;

    return 0;
}
