#include <bits/stdc++.h>
using namespace std;
#define ll long long



/**
SOLID ka S padh rahe hai.

S : Single responsibility principle.
This means that a class should have only 1 reason to change.


In the given below example in Invoice class :
      - If the calculateTotal() logic changes then class me kuch change karna padega because calculateTotal function me change kar rahe hai
      - If the printInvoice() logic changes then class me kuch change karna padega because printInvoice function me change kar rahe hai
      - If the saveToDatabase() logic changes then class me kuch change karna padega because saveToDatabase function me change kar rahe hai
      
  So this class can be changed by maximum 3 reasons. Hence this does NOT follow Single responsibility principle.

**/

class Pen {
  // we have made a pen class
  
public:
  
    string name;
    string color;
    int year;
    int price;
    
    Pen() {} // default constructor this is needed
    
    Pen(string name, string color, int year, int price) {
      this->name = name;
      this->color = color;
      this->year = year;
      this->price = price;
    }
    
  
};

class Invoice : public Pen {
  // this class deals with invoice of a purchase of a partitcular type of pen

  Pen p; // agar default constructor nhi rakhoge to ye nhi kar paoge
  int quantity;
public:
  
  
  Invoice(Pen p, int quantity) {
    this->p = p;
    this->quantity = quantity;
  }
  
  int calculateTotal() {
    // gives total price of this invoice
    
    int price = (p.price) * quantity;
    return price;
    
  }
  
  void printInvoice() {
    
    // let this function deals with printing the current Invoice given by some printing logic
  }
  
  void saveToDatabase() {
    
    // let this function deals with saving the current transaction invoice to database with some logic.

  }
  
  
};


int main() {
  
  Pen p("Parker", "Black", 2023, 200);
  Invoice i(p, 100);
  
  
  return 0;
  
}



/**

If we do some changes in the code and seperate the 3 functions that change the Invoice class into 3 new classes then 
Single responsibility principle will be followed in each of the class.

Benefits :: 
    - Hence code became easy to Maintain. Because agar kisi logic me change karna hai to sirf 1 class change karni hogi.
    - Code became easy to understand also.

**/

class Pen {
  // we have made a pen class
  
public:
  
    string name;
    string color;
    int year;
    int price;
    
    Pen() {} // default constructor this is needed
    
    Pen(string name, string color, int year, int price) {
      this->name = name;
      this->color = color;
      this->year = year;
      this->price = price;
    }
    
  
};

class Invoice : public Pen {
  // this class deals with invoice of a purchase of a partitcular type of pen

  Pen p; // agar default constructor nhi rakhoge to ye nhi kar paoge
  int quantity;
public:
  
  Invoice () {} // default constructor
  
  Invoice(Pen p, int quantity) {
    this->p = p;
    this->quantity = quantity;
  }
  
  int calculateTotal() {
    // gives total price of this invoice
    
    int price = (p.price) * quantity;
    return price;
    
  }
  
  
};

class InvoicePrinter : public Invoice {
  
  Invoice i;
  
public:
  
  InvoicePrinter(Invoice i) {
    this->i = i;
  }
  
  void printInvoice() {
    
    // let this function deals with printing the current Invoice given by some printing logic
    cout << "Print ho gai\n";
  }
  
  
};

class InvoiceToDatabase : public Invoice {
  
  Invoice i;

public:
  
  InvoiceToDatabase(Invoice i) {
    this->i = i;
  }
  
  void saveToDatabase() {
    
    // let this function deals with saving the current transaction invoice to database with some logic.

  }
  
};


int main() {
  
  Pen p("Parker", "Black", 2023, 200);
  Invoice i(p, 100);
  
  InvoicePrinter ip(i);
  
  cout << i.calculateTotal() << '\n';
  
  ip.printInvoice();
  
  
  return 0;
  
}

