// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Animal {
	
public:
	void walk() {
		cout << "Walking\n";
		
	}
	void eat() {
		cout << "Eating\n";
	}
	
};

class Dog : public Animal {

public:
	void talk() {
		cout << "Barking\n";
	}
};

/**
NOTE:: You can do
		 class Dog : Animal {}; but because this is class this will be private mode of inheritance by default.
		 struct Dog_struct : Animal_struct {}; this is struct this will be public mode of inheritance by default.  
**/

class Cat : public Animal {

public:
	void talk() {
		cout << "Meowwww\n";
	}
};

class Lion : public Animal {

public:
	void talk() {
		cout << "Roar\n";
	}
};

int main() {
	
	Dog d;
	Cat c;
	Lion l;
	
	d.eat();
	c.eat();
	l.talk();
	l.walk();
	d.walk();
	d.talk();
	c.talk();
	
	return 0;
}
