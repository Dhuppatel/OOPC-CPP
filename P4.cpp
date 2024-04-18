//this program is created to Develop a system to calculate the area of a shape
//created by Dhup patel
#include <iostream>
using namespace std;
float area(int radius) // Function to calculate the area of a circle
{
    return (3.14 * radius * radius);
}
int area(int side1, int side2) // Function to calculate the area of a rectangle
{
    return (side1 * side2);
}
int area(int hight, int width, int depth) // Function to calculate the volume of a cuboid
{
    return (hight * width * depth);
}
int main()
{
    int radius, hight, width, depth;
    float Areaofcircle;
    int areaofrectangle, areaofcuboid;
    cout << "Enter the radius of circle:"; // Input for the radius of the circle
    cin >> radius;
    Areaofcircle = area(radius); // Calculate and display the area of the circle
    cout << "The area of a circle " << Areaofcircle<<endl;

    cout << "Enter the height of rectangle:"; // Input for the height and width of the rectangle
    cin >> hight;
    cout << "Enter the width of rectangle :";
    cin >> width;

    areaofrectangle = area(hight, width);// Calculate and display the area of the rectangle
    cout << "The area of a rectangle :" << areaofrectangle<< endl;
   
    cout << "Enter the height of cuboid :";//input for cuboid
    cin >> hight;
    cout << "Enter the width of a cuboid :";
    cin >> width;
    cout << "Enter the depth of a cuboid  :";
    cin >> depth;
    areaofcuboid = area(hight, width, depth);//calculate and display the area of cuboid
    cout << "The area of a cuboid is :" << areaofcuboid;
    return 0;
}