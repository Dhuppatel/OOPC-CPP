//this program is created to Develop a system to calculate the area of circle
//created by Dhup patel
#include <iostream>
using namespace std;

class circle
{
    static int cnt;//static variable for counting of active members

    int radius;
    float area;

public:
    // Default constructor
    circle()
    {
        radius = 1;
        findarea();  // function to calculate the area
        cnt++;
    }

    // Parameterized constructor
    circle(int r)
    {
        cnt++;
        radius = r;
        findarea();
    }

    // Copy constructor
    circle(circle &a)
    {
        radius = a.radius;
        findarea();
        cnt++;
    }

    // Function to find  area of the circle
    void findarea()
    {
        area = radius * radius * 3.14;
        cout << "Circle with radius " << radius << " has area " << area << endl;
    }

    // Destructor
    ~circle()
    {
        cout << "Object is deleted" << endl;
        cnt--;
        getActiveObjects();
    }

    // function to get the count of active objects
    static void getActiveObjects()
    {
        cout << "Active Objects: " << cnt << endl;
    }
};

// static member intialization
int circle::cnt;

int main()
{

    circle *c1 = new circle;        // Default constructor
    circle *c2 = new circle(20);   // Parameterized constructor
    delete c2;
    delete c1;    
    circle *c3 = new circle;   // Copy constructor

    // Delete created objects
    delete c3;

    return 0;
}
