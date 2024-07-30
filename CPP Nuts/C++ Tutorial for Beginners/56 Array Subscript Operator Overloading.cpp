// || जय जय जय बजरंग बली ||

#include <iostream>
using namespace std;
#define ll long long

class Point {
	int arr[2];
public:
	
	Point(int x=0, int y=0) {
		arr[0] = x;
		arr[1] = y;
	}
	
	void print() {
		cout << arr[0] << " " << arr[1] << '\n';
	}
	
	// the return type of this function will always be address/reference of value of arr[pos] because in main function we might modify its value and hence to change its value at original location 
	// we must pass the reference of the value.
	int& operator [] (int pos) {
		if(pos == 0) {
			return arr[0];
		} 
		if(pos == 1) {
			return arr[1];
		}
		
		cout << "Out of bounds case.\n";
		exit(0);
	}
};


int main() {
	
	Point p1(1,2);
	p1.print();
	
	p1[0] = 2; // i.e calling p1[0] will help us get the location of arr[0] of object p1. And then we modify it with 2, this change will also be reflected in original arr[0] of the object.
	p1[1] = 3;
	
	p1.print();
	
	p1[2] = 3; // out of bounds hence code will exit because we made it so and nothing run below this line.
	p1.print();
	return 0;
}
