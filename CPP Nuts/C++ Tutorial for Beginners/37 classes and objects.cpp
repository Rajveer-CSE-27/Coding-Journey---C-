// || जय जय जय बजरंग बली ||
#include <iostream>
#include <string>
using namespace std;

class Phone { // There is a rule not necessary that class name start with upper case letter.
    
    // by default the access specifier is private. i.e we cannot change it outside the current class.
    string name;
    string model;

public: // from now everything is public.
    
    Phone(string phone_name, string phone_model) { // this is the constructor that get automatically called when we create an object of the class.
        name = phone_name;
        model = phone_model;
        // inside the constructor we may or may not give values to all the attributes that are declared.
    }
    
    void makeCall() {
        cout << "Calling from :: " << name << " " << model << '\n';
        return;
    }
    void receiveCall() {
        cout << "Receiving call in :: " << name << " " << model << '\n';
        return;
    }
    
}; // class ke end me ; is necessary because it represents a statement. And to end a statement we must use ;


int main() {
    
    // iphone is the object of Phone class which will use Phone class as its bluePrint.
    
    Phone iphone("Apple iPhone", "14 pro max"); 
    Phone onePlus = Phone("onePlus", "Nord CE3");
    // above both are the ways to create an object of the class. The above objects are created in c++ stack. And they are deleted once we finish the current function (here main function).
    
    Phone* oppo = new Phone("Oppo", "A15 2020");
    // the above method of creating an object is also valid. The object is crated in c++ heap. And when we go outside the current function, the object still stays in heap.
    
    iphone.makeCall();
    onePlus.receiveCall();
    oppo->makeCall();
    
    //iphone.name = "Hi"; This is invalid because name is private so we cannot change it outside the class
    
    delete oppo; // only way to delete this type of object in heap. Otherwise it would stay there.
    
    return 0;
}
