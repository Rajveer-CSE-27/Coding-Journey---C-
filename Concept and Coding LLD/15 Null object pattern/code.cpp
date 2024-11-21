#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

Handling Null object
**/
 

class Vehicle {
// pure abstract class i.e interface
  
public:
  
  virtual int getNumberOfSeats() = 0;
  virtual int getTankCapacity() = 0;
  
};

class Car : public Vehicle {
public:
  
  Car() {}
  
  int getNumberOfSeats() {
    return 5;
  }
  int getTankCapacity() {
    return 200;
  }
  
};

class Bike : public Vehicle {
public:
  
  Bike() {}
  
  int getNumberOfSeats() {
    return 2;
  }
  int getTankCapacity() {
    return 20;
  }
  
};


// this class made to avoid null object creation
class NullObject : public Vehicle {
  
public:
  
  NullObject() {}
  
  int getNumberOfSeats() {
    // behaviour of null object
    return 0;
  }
  
  int getTankCapacity() {
    return 0;
  }
  
};

class VehicleController {
  
public:
  
  VehicleController() {}
  
  Vehicle* temp;
  
  Vehicle* getVehicleObject(string name) {
    
    if(name == "Car") {
      temp = new Car();
      return temp;
    }
    if(name == "Bike") {
      temp = new Bike();
      return temp;
    }
    
    temp = new NullObject();
    return temp;
    
  }
  
};

 
int main() {
  
  
  VehicleController vc;
  
  Vehicle* v = vc.getVehicleObject("Car");
  cout << v->getNumberOfSeats() << " " << v->getTankCapacity() << '\n';
  
  v = vc.getVehicleObject("Truck");
  cout << v->getNumberOfSeats() << " " << v->getTankCapacity() << '\n';
  
  return 0;
}


