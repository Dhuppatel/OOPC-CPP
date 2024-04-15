#include <iostream>
using namespace std;

class circle
{
    
    static int cnt;    // Static member 

    int radius;
    float area;

public:
    // Default constructor
    circle()
    {
        radius = 1;
        findarea();   //function call to calculate and display the area  
        cnt++;       
    }

    // Parameterized constructor 
    circle(int r)
    {
        cnt++;       
        radius = r;
        findarea();  //function call to calculate and display the area
    }

    // Copy constructor
    circle(circle &a)
    {
        radius = a.radius;
        findarea();   //function call to calculate and display the area
        cnt++;       
    }

    // function to find  the area of the circle
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

    // static function to get the count of active objects
    static void getActiveObjects()
    {
        cout << "Active Objects: " << cnt << endl;
    }
};

// static variable intialization 
int circle::cnt=0;

int main()
{
  
    circle c1;         // default constructor
    circle c2(20);     // parameterized constructor
    circle c3(c1);     // copy constructor

    return 0;
}
