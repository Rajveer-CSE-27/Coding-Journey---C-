#include <bits/stdc++.h>
using namespace std;
#define ll long long



/**
SOLID ka O padh rahe hai.


Let tumhara saveInvoice class perfectly chal raha hai.
But tumhe ab ek aur functionality add karni hai.
Along with savingToDatabase you also want to save it to File.

So if you make saveToFile() in saveInvoice class, this is called modification and it is not encouraged in OOPs.
Rather tum saveInvoice class ko aise define karo such that functionalities tum add kar pao by extending the class rather than modifying the class.

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
  
  Pen p;
  int quantity;

public:
  
  Invoice() {}
  
  Invoice(Pen p, int quantity) {
    this->p = p;
    this->quantity = quantity;
  }
  
  
};

class saveInvoice : public Invoice {

  Invoice i;

public:
  
  saveInvoice(Invoice i) {
    this->i = i;
  }  
  
  void saveToDatabase() {
    // code to save current invoice to database
  }

};



int main() {
  
  Pen p("Parker", "Black", 2023, 10);
  Invoice i(p, 200);
  
  
  return 0;
  
}



/**

Hence let hum saveInvoice wali class ko abstract bana dete hai using virtual function.
Jisse usko extend kar karke hum new classes bana paaye and main cheez ya dusre childrens ko modify naa kare


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
  
  Pen p;
  int quantity;

public:
  
  Invoice() {}
  
  Invoice(Pen p, int quantity) {
    this->p = p;
    this->quantity = quantity;
  }
  
  
};

class SaveInvoice : public Invoice {

  Invoice i;

public:
  
  SaveInvoice() {}
  
  SaveInvoice(Invoice i) {
    this->i = i;
  }  
  
  virtual void save(Invoice i) {}
  
  // save wale function ko humne virtual bana diya hai yaani define yaha nhi hoga
  // but iske requirements ke according iske child classes me hoga
  
  // note :: virtual void save (Invoice i) override {}
  // agar ye karte to jitne bhi child hote usme agar hum save define karte hai to sirf 1 parameter : Invoice i hi daalna padta, jo humne SaveToFile ke save me extra parameter daalein hai vo nhi kar paatein
  

};

class SaveToDatabase : public SaveInvoice {
  
  SaveInvoice i;
  
public:
  
  SaveToDatabase(SaveInvoice i) {
    this->i = i;
  }
  
  void save() {
    // code to save in database
    cout << "Saved to Databse\n";
  }
  
};

class SaveToFile : public SaveInvoice {
  
  SaveInvoice i;
  string fileName;
  
public:
  
  SaveToFile(SaveInvoice i, string fileName) {
    this->i = i;
    this->fileName = fileName;
  }
  
  void save() {
    // code to save in database
    cout << "Saved to file : " << fileName << '\n';
    
  }
  
};



int main() {
  
  Pen p("Parker", "Black", 2023, 10);
  Invoice i(p, 200);
  
  
  SaveInvoice si(i);
  SaveToDatabase sd(si);
  sd.save();
  SaveToFile sf(si, "Deskop/main");
  sf.save();
  
  
  return 0;
  
}


