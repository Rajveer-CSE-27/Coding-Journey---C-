#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Strategy design pattern : 
    Used when multiple children need same piece of code which is not present in base class.
    Hence to save ourself from writing repeated code we apply this technique.
**/


// Problem Scenario

// class Vehicle {
  
// public:
  
//   void drive() {
    
//     cout << "Vehicle is driving normally.\n";
//   }
  
// };

// class SportVehicle : public Vehicle {

// public:
  
//   void drive() {
    
//     cout << "Vehicle is driving fast.\n"; // code1 in notes
//   }
// };

// class HeavyVehicle : public Vehicle {

// public:
  
//   void drive() {
    
//     cout << "Vehicle is driving slow.\n";// code 2 in notes
//   }
// };

// class OffRoadVehicle : public Vehicle {

// public:
  
//   void drive() {
    
//     cout << "Vehicle is driving fast.\n";//code 1 in notes
//   }
// };

// class PassengerVehicle : public Vehicle {

// public:
  
//   // this implements drive() as in Vehicle class
// };


// // here We have written code1  multiple times and need to avoid it.


// int main() {
  
//   SportVehicle s;
//   HeavyVehicle h;
//   OffRoadVehicle o;
//   PassengerVehicle p;
  
//   s.drive();
//   h.drive();
//   o.drive();
//   p.drive();

//   return 0;
  
// }


// Using Strategy Design Pattern




class DriveClass {
  // making the DriveClass as interface i.e in C++ making it an abstract class
public:
    
    
  virtual void drive() = 0;
  // Making this class abstract by declaring pure virtual function
  
};

class Fast : public DriveClass {

public:
  
  
  // implementing pure virtual function of parent class
  void drive() {
    cout << "Vehicle is driving fast\n";
  }  
  
};
class Slow : public DriveClass {

public:

  void drive() {
    cout << "Vehicle is driving slow\n";
  }  
  
};
class Normal : public DriveClass {

public:

  void drive() {
    cout << "Vehicle is driving normally\n";
  }  
  
};



class Vehicle{
  
public:
  
  DriveClass *d;
  // as DriveClass is an abstract class we cannot make object of it.
  // Rather pass the pointer of the object of this class when required
  
  Vehicle() {}
  // default constructor
  
  Vehicle(DriveClass *d) {
    this->d = d;
  }
  
  // drive function of this class
  void drive() {
    d->drive();
  }
  
  
};

class SportVehicle : public Vehicle {
public:
  
    
    // passing the parameter i.e address of f in vehicle constructor through initializer list.
    
    Fast f;
    SportVehicle() : Vehicle(&f) {}
  
  
};

class HeavyVehicle : public Vehicle {
public:
  
  Slow f;
  HeavyVehicle() : Vehicle(&f) {}
  
};

class OffRoadVehicle : public Vehicle {
public:
  
  Fast f;
  OffRoadVehicle() : Vehicle(&f) {}
  
};

class PassengerVehicle : public Vehicle {
public:
  
  Normal f;
  PassengerVehicle() : Vehicle(&f) {}
  
};


// here We have written code1  multiple times and need to avoid it.


int main() {
  
  
  SportVehicle s;
  
  HeavyVehicle h;
  OffRoadVehicle o;
  PassengerVehicle p;
  
  s.drive();
  h.drive();
  o.drive();
  p.drive();

  return 0;
  
}

// This is how with strategy design pattern we make the code DRY.
