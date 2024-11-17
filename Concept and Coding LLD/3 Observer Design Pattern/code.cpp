#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Observer design pattern

  -> Observer interface
  -> Observable interface
  
  -> Get the observable object as a constructor injection in observer class. So that code for update gets easier


Problem :: 
  Design LLD for notify when back in stock for Iphone on Amazon.
  Currently iphone is out of stock.
  
  Some users want notification on their email and some on their mobile
  
**/

class ObserverInterface {
  
public:
    
  virtual void update() = 0; // pure virtual function
  
  // making this class abstract
  
};



class ObservableInterface {
  
public:
    
  virtual void add(ObserverInterface* obj) {};
  // adds the observer to the list of observers
  
  virtual void remove(ObserverInterface* obj) {};
  // removes the observer from the list of observers
  
  virtual void notifyObservers() {};
  // notifies all observers when there is change in the system
  
  virtual void setStock(int t) {};
  // modify the stock of Observable item.
    
};

class EmailObserverClass : public ObserverInterface {

public:

  string email;
  ObservableInterface obj; // V.V.V important step to declare observableInterface object here.
  // so that constructor se obj leke isme assign kar denge.
  
  EmailObserverClass(string email, ObservableInterface obj) {
    this->email = email;
    this->obj = obj;
  }  
  
  void sendMail(string email, string message) {
    cout << "Mail sent to : " << email << '\n';
  }
  
  void update() {
    
    // update is called when notifyObservers() called in observable class.
    
    sendMail(email, "Product is back in stock");
  }
  
  
};

class MobileObserverClass : public ObserverInterface {

public:

  string number;
  ObservableInterface obj; // V.V.V important step to declare observableInterface object here.
  // so that constructor se obj leke isme assign kar denge.
  
  
  MobileObserverClass(string number, ObservableInterface obj) {
    this->number = number;
    this->obj = obj;
  }  
  
  void sendMessage(string number, string message) {
    cout << "Mail sent to : " << number << '\n';
  }
  
  void update() {
    
    // update is called when notifyObservers() called in observable class.
    sendMessage(number, "Product is back in stock");
  }
  
  
};


class IphoneObservableClass : public ObservableInterface{
  
public:
  
  set<ObserverInterface*> observerList;
  int currentStock = 0;
  
  void add(ObserverInterface *obj) {
    observerList.insert(obj);
  }
  
  void remove(ObserverInterface *obj) {
    
    observerList.erase(obj);
    
  }
  
  void notifyObservers() {
    
    for(ObserverInterface* obj:observerList) {
      
      obj->update();
    }
    
  }
  
  void setStock(int t) {
    
    
    if(currentStock == 0) {
      notifyObservers();
      // becuase ab stock aane wala hai
    }
    
    currentStock = t;
  }
  
  int getStock() {
    return currentStock;
  }
  
};

// we can add Observable class for other items also if we want



int main() {
  
  IphoneObservableClass iphoneStock;
  
  ObserverInterface *obj;
  
  EmailObserverClass observer1("abc@gmail.com", iphoneStock);
  obj = &observer1;
  iphoneStock.add(obj);
  
  EmailObserverClass observer2("pqr@gmail.com", iphoneStock);
  obj = &observer2;
  iphoneStock.add(obj);
  
  MobileObserverClass observer3("9539382892", iphoneStock);
  obj = &observer3;
  iphoneStock.add(obj);
  
  

  iphoneStock.setStock(100);
  
  cout << iphoneStock.getStock() << '\n';  
  
  iphoneStock.setStock(0);
  
  obj = &observer2;
  iphoneStock.remove(obj);
  
  iphoneStock.setStock(2);
  
  
  
  return 0;
}


