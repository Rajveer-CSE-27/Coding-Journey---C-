#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Abstract Factory design pattern
**/

class Vehicle {
// abstract class vehicle  

public:
  
  virtual void manufacture() = 0;
  // pure virtual function
  
};

class LuxuryVehicle1 : public Vehicle {
  
public:
  
  void manufacture() {
    
    cout << "LuxuryVehicle 1 manufactured\n";
  }
  
};

class LuxuryVehicle2 : public Vehicle {
  
public:
  
  void manufacture() {
    
    cout << "LuxuryVehicle 2 manufactured\n";
  }
  
};

class OrdinaryVehicle1 : public Vehicle {
  
public:
  
  void manufacture() {
    
    cout << "OrdinaryVehicle 1 manufactured\n";
  }
  
};

class OrdinaryVehicle2 : public Vehicle {
  
public:
  
  void manufacture() {
    
    cout << "OrdinaryVehicle 2 manufactured\n";
  }
  
};

class VehicleFactory {
  
// abstract class for main factory
  
public:
  
    virtual Vehicle* getVehicle(string input) = 0;
};

class LuxuryFactory : public VehicleFactory {
  
public:
  
  
  Vehicle* getVehicle(string input) {
    
    if(input == "LuxuryVehicle1") {
      return new LuxuryVehicle1();
    } else {
      return new LuxuryVehicle2();
    }
  }
  
};

class OrdinaryFactory : public VehicleFactory {
  
public:
  
  Vehicle* getVehicle(string input) {
    
    if(input == "OrdinaryVehicle1") {
      return new OrdinaryVehicle1();
    } else {
      return new OrdinaryVehicle2();
    }
  }
  
};



 
int main() {
  
  VehicleFactory *vf;
  
  vf = new LuxuryFactory();
  
  Vehicle* v = vf->getVehicle("LuxuryVehicle1");
  
  v->manufacture();
  
  vf = new OrdinaryFactory();
  v = vf->getVehicle("OrdinaryVehicle2");
  v->manufacture();
  
  return 0;
}


