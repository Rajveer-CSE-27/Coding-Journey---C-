// || जय जय जय बजरंग बली ||

#include <iostream>
using namespace std;
#define ll long long

class Point {
	int x;
	int y;
public:
	
	Point(int x=0, int y=0) : x{x},y{y} {}
	
	
	// if we do no use operator overloading then we need to make functions
	Point add(const Point& rhs) {
		Point ans;
		ans.x = x + rhs.x;
		ans.y = y + rhs.y;
		return ans;
	}
	
	Point mul(const Point& rhs) {
		Point ans;
		ans.x = x * rhs.x;
		ans.y = y * rhs.y;
		return ans;
	}
	
	Point sub(const Point& rhs) {
		Point ans;
		ans.x = x - rhs.x;
		ans.y = y - rhs.y;
		return ans;
	}
	
	void print() {
		cout << x << " " << y << '\n';
	}
	
	// if we use operator overloading....
	
	Point operator + (const Point& rhs) {
		Point ans;
		ans.x = x + rhs.x; // in RHS of this equation the first x is of object that called this function.
		ans.y = y + rhs.y;
		return ans;
	}
	
	Point operator - (const Point& rhs) {
		Point ans;
		ans.x = x - rhs.x;
		ans.y = y - rhs.y;
		return ans;
	}
	
	Point operator * (const Point& rhs) {
		Point ans;
		ans.x = x * rhs.x;
		ans.y = y * rhs.y;
		return ans;
	}
	
	
};

int main() {
	
	// if we do not use operator overloading then for big expressions we have to right big code and also hard to understand, find error.
	
	Point p1(1,4), p2(3,6), p3(0,-2);
	
	// (p1 + p2) * (p3 - p2) * (p1 * p3);
	Point p4 = p1.add(p2); // 4,10
	Point p5 = p3.sub(p2); // -3, -8
	Point p6 = p1.mul(p3); // 0, -8
	
	p4 = p4.mul(p5); // -12, -80
	p4 = p4.mul(p6); // 0, 640
	p4.print();
	
	// but if we use inbuilt operators (+, -, *, /, etc) instead of creating functions then it would be easy to understand.
	
	
	Point res = (p1 + p2) * (p3 - p2) * (p1 * p3); // we wrote the same thing with so much shorter and easy to understand code.
	res.print();
	
	return 0;
}
