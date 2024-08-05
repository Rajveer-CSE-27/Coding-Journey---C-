// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Youtuber {
	int x;
public:
	
	Youtuber(int x) : x{x} {
		cout << "Youtuber constructor\n";
	}
	
	void video() {
		cout << "Video function in Youtuber class\n";
	}
	void work() {
		cout << "Work function in Youtuber class\n";
	}
};

class Engineer {
	int y;
public:
	
	Engineer(int y) : y{y} {
		cout << "Engineer constructor\n";
	}
	
	void code() {
		cout << "Code function in Engineer class\n";
	}
	void work() {
		cout << "Work function in Engineer class\n";
	}
};

class Student : public Youtuber, public Engineer {
public:
	
	Student(int x, int y) : Youtuber(x), Engineer(y) {
		cout << "Student constructor\n";
	}
};

int main(){
	
	Student s1(1,2);
	s1.video();
	s1.code();
	
	//s1.work(); calling this will generate error "request for member 'work' is ambiguous"
	
	// to handle this there are 3 methods
	
	//1. Explicitly calling the function with the required base class
	s1.Engineer::work();
	s1.Youtuber::work();
	
	//2. Slicing the original object s1 into another object such that functionality of a particular class is only present in that sliced object
	Engineer e1 = s1;
	e1.work();
	Youtuber y1 = s1; // here y1 is a sliced version of s1 that has functionality of yotuber and student only
	y1.work();
	
	//3. static casting the current object of into a base class object. And using the functionality of that base class at that instance only
	static_cast<Engineer>(s1).work();
	s1.video();
	static_cast<Youtuber>(s1).work(); // s1 will have only functionalities of youtuber class at this instance only
	s1.code(); 
	
    return 0;
}
