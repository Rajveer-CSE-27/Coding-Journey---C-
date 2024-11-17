#include <bits/stdc++.h>
using namespace std;
#define ll long long



/**
SOLID ka I padh rahe hai.

Here apan waiter class me bhi restaurantEmployee ke saarein functions likh rahe hai jabki not necessary

C++ me chalta hai agar hum na implement karein to but java me interface me nhi chalta

**/

class RestaurantEmployee {
  
public:
  
  virtual void washDishes() {}
  virtual void serveCustomers() {}
  virtual void cookFood() {}
  
};

class Waiter : public RestaurantEmployee {

public:
  
  void washDishes() {}
  void serveCustomers() {}
  void cookFood() {}
  
};

class Chef : public RestaurantEmployee {

public:
  
  void washDishes() {}
  void serveCustomers() {}
  void cookFood() {}
  
};

int main() {
  
  
 
  return 0;
}


/**

alag alag interfaces create kardo jisse classes me saarein functions na implement karna pade

**/

class WaiterInterface {
  
public:
  
  virtual void serveCustomers() {}
  virtual void takeOrder() {}
  
};

class CookInterface {
  
public:
  
  virtual void cookFood() {}
  virtual void decideMenu() {}
  
};


class Waiter : public WaiterInterface {

public:
  
  void serveCustomers() {}
  void takeOrder() {}
  
};

class Chef : public CookInterface {

public:
  
  void cookFood() {}
  void decideMenu() {}
  
};

int main() {
  
  
 
  return 0;
}

