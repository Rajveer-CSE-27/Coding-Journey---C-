#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Decorator design pattern :: 

  -> an object with additional features is also a valid object.
  -> The relationship of ExtraFeature class and Base class is both : 
        - has-a relationship
        - is-a relationship
  
**/

// abstract base class
class Pizza {
  
public:
  
  virtual int cost() = 0;
  // pure virtual function
  // cost will give cost of the pizza
  
};


class Margeritta : public Pizza {
  
public:
  
  int cost() {
    return 100;
  }
  
};

class VeggieDelight : public Pizza {
  
public:
  
  int cost() {
    return 175;
  }
  
};
class Chicken : public Pizza {
  
public:
  
  int cost() {
    return 200;
  }
  
};


// abstract extra features class
// because of is-a relationship the extra feature class will be a subclass of Base class
class Toppings : public Pizza {
  
public:
  // this will automatically have pure virtual function cost
  // because it is subclass of abstract Base class
  
  Pizza *pizza;
  // creating an object of pizza class that would be assigned by constructor injection
  // because this class follows : has-a relationship with base class 
  
};

class ExtraCheese : public Toppings {
  
public:
  
  
  // calling the interior object through constructor injection
  ExtraCheese(Pizza* pizza) {
    this->pizza = pizza;
  }
  
  int cost() {
    
    int ans = pizza->cost() + 25;
    return ans;
    
  }
  
};

class Mushroom : public Toppings {
  
public:
  
  
  // calling the interior object through constructor injection
  Mushroom(Pizza* pizza) {
    this->pizza = pizza;
  }
  
  int cost() {
    
    int ans = pizza->cost() + 30;
    return ans;
    
  }
  
};

class Jalepeno : public Toppings {
  
public:
  
  
  // calling the interior object through constructor injection
  Jalepeno(Pizza* pizza) {
    this->pizza = pizza;
  }
  
  int cost() {
    
    int ans = pizza->cost() + 10;
    return ans;
    
  }
  
};


int main() {
  
  
  Pizza* pizza = new Margeritta();
  // pizza is normal simple margeritta pizza
  
  cout << pizza->cost() << '\n';
  
  pizza = new ExtraCheese(pizza);
  // we added extra cheese to it
  
  cout << pizza->cost() << '\n';
  
  
  pizza = new Mushroom(new Jalepeno(pizza));
  // we first added jalepeno to it then Mushroom
  
  cout << pizza->cost() << '\n';
  
  
  
  
  
  return 0;
}


