#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**

Let us see where Liskov substitution problem occurs

**/

class Vehicle {

public:
  
  int getNumberOfWheels()  {
    return 2;
  }
  
  bool hasEngine(){
    return true;
  }
  
};

class Motorcycle : public Vehicle {
  
public:
  
  Motorcycle() {}
  
};

class Car : public Vehicle {
public:
  
  Car() {}
  
  int getNumberOfWheels() {
    return 4;
  }
  
};


class Bicycle : public Vehicle {
  
public:
  
  Bicycle() {}
  
  bool hasEngine() {
    
    // here we are able to call this function. Even though it should not be allowed to call this function
    // has Bicycle has no concept of Engine.
    // so to stop this at compile time we must solve this
    
    return false;
  }
  
};


int main() {
  
  
  Motorcycle m;
  Bicycle b;
  Car c;
  
  cout << m.hasEngine() << '\n';
  cout << b.hasEngine() << '\n'; // this should not be allowed at compile time.
  cout << c.hasEngine() << '\n';
  

  return 0;
  
}


/**
Try to keep generic things in the parent class only.
And if required create more subclasses.

**/

class Vehicle {

public:
  
  int getNumberOfWheels()  {
    return 2;
  }
  
};

class VehicleWithEngine : public Vehicle {

public:
  
  bool hasEngine() {
    return true;
  }
  
};

class Motorcycle : public VehicleWithEngine {
  
public:
  
  Motorcycle() {}
  
};

class Car : public VehicleWithEngine {
public:
  
  Car() {}
  
  int getNumberOfWheels() {
    return 4;
  }
  
};


class Bicycle : public Vehicle {
  
public:
  
  Bicycle() {}
  
  
};


int main() {
  
  
  Motorcycle m;
  Bicycle b;
  Car c;
  
  cout << m.hasEngine() << '\n';
  cout << b.hasEngine() << '\n'; // here this line will throw compile time error.
  
  cout << b.getNumberOfWheels() << '\n';
  cout << c.hasEngine() << '\n';
  

  return 0;
  
}
