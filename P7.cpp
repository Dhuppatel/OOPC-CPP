#include <iostream>
#include <iomanip>
using namespace std;
class complex
{
    float real;
    float imginary;

public:
    complex() {}
    complex(double a, double b)//paramiterized constructor for intializing complex number
    {
        real = a;
        imginary = b;
    }
    void getdata()     // Method to get data from user
    {
        cout << "Enter Real part :";
        cin >> real;
        cout << "Enter Imaginary part :";
        cin >> imginary;
    }
    void putdata()   // Method to put data
    {
        cout << real;
        if (imginary < 0)
        {
            cout << imginary << "i" << endl;
        }
        else
        {
            cout << "+" << imginary << "i" << endl;
        }
    }

    complex operator+(complex &x)  // Overloaded + operator for addition
    {
        complex temp;
        temp.real = real + x.real;
        temp.imginary = imginary + x.imginary;
        return temp;
    }
    complex operator-(complex &x)   // Overloaded - operator for subtraction
    {
        complex temp;
        temp.real = real - x.real;
        temp.imginary = imginary - x.imginary;
        return temp;
    }
    complex operator*(complex &x)   // Overloaded * operator for subtraction
    {
        complex temp;
        temp.real = real * x.real - imginary * x.imginary;
        temp.imginary = real * x.imginary + x.real * imginary;
        return temp;
    }
    complex operator/(complex &x)  // Overloaded / operator for subtraction
    {
        complex temp;
        double denominator;
        denominator = x.real * x.real + x.imginary * x.imginary;
        if (denominator == 0)
        {
            cout << "Error division by Zero.....";
            return complex(0, 0);
        }

        temp.real = real / x.real;
        temp.imginary = imginary / x.imginary;
        return temp;
    }
    complex operator!()   // Overloaded ! operator for subtraction
    {
        complex temp;
        temp.real = -real;
        temp.imginary = -imginary;
        return temp;
    }
};
int main()
{
    complex c1, c2, result;
    c1.getdata();
    c2.getdata();
    char oprator;
    cout << "Choose Opration :";

    cout << "(+) addition" << endl
         << "(-) subtraction" << endl
         << "(*) multiplication" << endl;
    cout << "(/) division" << endl
         << "(!) negation" << endl
         << "Enter your choice :";
    cin >> oprator;
    switch (oprator)
    {
    case '+':
        result = c1 + c2;
        result.putdata();
        break;
    case '-':
        result = c1 - c2;
        result.putdata();
        break;
    case '*':
        result = c1 * c2;
        result.putdata();
        break;
    case '/':
        result = c1 / c2;
        result.putdata();
        break;
    case '!':
        result = !c1;
        result.putdata();
        result = !c2;
        result.putdata();

    default:
        break;
    }

    return 0;
}