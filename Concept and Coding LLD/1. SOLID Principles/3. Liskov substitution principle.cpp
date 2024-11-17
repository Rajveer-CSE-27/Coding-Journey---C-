#include <bits/stdc++.h>
using namespace std;
#define ll long long



/**
SOLID ka L padh rahe hai.


Given example me Bicycle class is a subclass of Bike class.
But bicycle me engine hota hi nhi to start kahaan se karenge. Hence it does not extend the functionalities of parent rather narrows it.

Hence this should not be written like this.

**/


class Bike {
  
public:
  
  virtual void turnOnEngine() {};
  virtual void accelerate() {};
  
};

class Motorcycle : public Bike {
  
  bool isEngineOn = false;
  int speed = 0;
  
public:
  
  void turnOnEngine() {
    isEngineOn = true;
  }
  
  void accelerate() {
    speed += 10;
    
  }
  
  bool checkEngineOn() {
    return isEngineOn;
  }
  
  int getSpeed() {
    return speed;
  }
  
};

class Bicycle : public Bike {
  
  int speed = 0;
  
public:
  
  void turnOnEngine() {
    
    throw runtime_error("Bicycle has no engine to start");
  }
  
  void accelerate() {
    speed += 5;
  }
  
};

int main() {
  
  
  Motorcycle m;
  m.turnOnEngine();
  cout << m.checkEngineOn() << '\n';
  cout << m.getSpeed() << '\n';
  m.accelerate();
  cout << m.getSpeed() << '\n';
  
  Bicycle b;
  b.turnOnEngine(); // this throws a runtime error.
  
  
  return 0;
  
}



