// || जय जय जय बजरंग बली ||
#include <iostream>
using namespace std;

class Point{
    double x;
    double y;

public:
    
    Point() { // this is the default constructor where we provide a default value to attributes and there are no input parameters.
        x = 0;
        y = 0;
        cout << "Default constructor called.\n";
    } 
    
    Point(double X, double Y) { // this is a parameterized constructor where we get some parameters and assign it to attributes.
        x = X;
        y = Y;
        cout << "Parameterized constructor called.\n";
    }
    
    Point(const Point& rhs) { // this is a copy constructor where we take an already defined object as a constant value (so that we cannot change it), and copy the required attributes of that object in our new object. 
        // the input parameter type is an object of the same class. And it must be constant.
        
        x = rhs.x;
        y = rhs.y;
        // we may or may not copy all the attributes.
        
        cout << "Copy constructor called.\n";
    }
    
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
};

int main() {
    
    Point p1;
    
    Point p2(1.4, 3.6);
    
    cout << p2.getX() << " " << p2.getY() << '\n';
    
    Point p3(p2);
    cout << p3.getX() << " " << p3.getY() << '\n';
    
    return 0;
}
