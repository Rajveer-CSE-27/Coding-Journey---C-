// || जय जय जय बजरंग बली ||

#include <iostream>
using namespace std;
#define ll long long

class Test {
	int v;
public:
	
	Test(int a = 0) :v{a} {}
	
	friend istream& operator >> (istream& input, Test& obj); // making >> operator overloading function as friend of this class so it can access all data of this class whether public, private or protected
	friend ostream& operator << (ostream& output, Test& obj);// making << operator overloading function as friend of this class
	
	// if we do not want to access any private data members then no need of friend keyword.
};

// these functions will be of istream and ostream classes respectively.


istream& operator >> (istream& input, Test& obj) { // here we named cin {object of istream class} as input
	input >> obj.v; // this line is same as cin >> obj.v
	return input; // here we are returning input i.e cin and hence we can do multiple >> at a time.
}

ostream& operator << (ostream& output, Test& obj) { //here we named cout {object of ostream class} as output
	output << obj.v << '\n'; // this line is same as cout << obj.v
	return output;// here we are returning output i.e cout and hence we can do multiple << at a time.
}


int main() {
	
	Test t;
	int a;
	
	cin >> t >> a; // why this multiple >> works is explained in notes. {becuase we returned cin in >> operator overloading function}
	
	cout << t << a;
	
	return 0;
}
