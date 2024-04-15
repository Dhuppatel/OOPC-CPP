#include <bits/stdc++.h>
using namespace std;
class product   // Base class for product
{
protected:
    int product_id;
    string product_name;         // with space
    string product_manufacturer; // without space
    float product_price;         // fractional nummber
public:
 // Constructor to initialize product data
    product(int a, string b, string c, float d)
    {
        product_id = a;
        product_name = b;
        product_manufacturer = c;
        product_price = d;
    }
    // Virtual function to display product data
    virtual void putdata() = 0;// Pure virtual function to enforce implementation in derived classes
};
// Derived class for smartwatches
class smartwatch : protected product
{
protected:
    float dial_size;
public:
    smartwatch();
    // Parameterized constructor to initialize smartwatch data
    smartwatch(int w, string x, string y, float z, float dial) : product(w, x, y, z)
    {
        dial_size = dial;
    }
    // Function to display smartwatch data
    void putdata()
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price;
        cout << " : " << dial_size << endl;
        cout << "--------------------------------------------------------------------------------";
    }
};

// Derived class for bedsheets

class bedsheet : protected product
{
protected:
    float height, width;    // Derived class for bedsheets
public:
    bedsheet();
     // Parameterized constructor to initialize bedsheet data
    bedsheet(int w, string x, string y, float z, float p, float q) : product(w, x, y, z)
    {
        height = p;
        width = q;
    }
    // Function to display bedsheet data

    void putdata()
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price;
        cout << " : " << width << " : " << height << endl;
        cout << "--------------------------------------------------------------------------------";
    }
};
int main()
{
    int id;
    string name,manufacturer;
    float price;
    int choice;
       // Prompt the user to select a product type
    cout <<"Enter 1 : smart watch menu"<<endl;
    cout <<"Enter 2 : bedsheet menu"<<endl;
    cout<<"Enter your choice :";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"Enter product ID:";
        cin>>id;
        cout<<"Enter product name:";
        fflush(stdin);
        getline(cin,name);
        cout<<"Enter product manufacturer:";
        fflush(stdin);
        cin>>manufacturer;
        cout<<"Enter product price :";
        cin>>price;

        float dial;
        cout<<"Enter product dial size :";
        cin>>dial;
         // Create a smartwatch object and display its details
        smartwatch *p1;
        p1=new smartwatch(id,name,manufacturer,price,dial);
        p1->putdata();
        break;
     case 2: 
     // Input bedsheet details from the user
     cout<<"Enter product ID:";
        cin>>id;
        cout<<"Enter product name:";
        fflush(stdin);
        getline(cin,name);
        cout<<"Enter product manufacturer:";
        fflush(stdin);
        cin>>manufacturer;
        cout<<"Enter product price :";
        cin>>price;

        float width,height;
        cout<<"Enter bedsheet width  :";
        cin>>width;
        cout<<"Enter bedsheet height :";
        cin>>height;
        // Create a bedsheet object and display its details
        bedsheet *p2;
        p2=new bedsheet(id,name,manufacturer,price,height,width);
        p2->putdata();
        break;
    default:
        break;
    }
     return 0;
}