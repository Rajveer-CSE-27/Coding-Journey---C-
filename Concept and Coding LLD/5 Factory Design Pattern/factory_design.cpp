#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Factory design pattern
**/

class ShapeInterface {
  
public:
  
  virtual void draw() = 0;
  // pure virtual function hence making this class static
  
};

class Circle : public ShapeInterface {
  
public:
  
  void draw() {
    cout << "Circle is drawn\n";
  }
  
};
class Triangle : public ShapeInterface {
  
public:
  
  void draw() {
    cout << "Triangle is drawn\n";
  }
  
};
class Square : public ShapeInterface {
  
public:
  
  void draw() {
    cout << "Square is drawn\n";
  }
  
};

// making the factory class
class ShapeFactory {
  
public:
    
    
  // logic for creating objects conditionally
  ShapeInterface* getShape(string input) {
    // returns the created object
    
    if(input == "Circle") {
      return new Circle();
    } else if(input == "Triangle") {
      return new Triangle();
    } else {
      return new Square();
    }
    
  }
  
};


int main() {
  
  
  ShapeFactory sf;
  ShapeInterface* shape = sf.getShape("Circle");
  
  shape->draw();  
  
  shape = sf.getShape("Square");
  shape->draw();
  
  return 0;
}


