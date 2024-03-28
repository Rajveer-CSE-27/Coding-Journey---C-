#include <bits/stdc++.h>
using namespace std;

/**
Linear Diophantine Equation ::

	-> A Linear Diophantine Equation (in two variables) is an equation of the general form: ax + by = c.
	   Where a , b and c are known variables while x and y are unknown.
	
	-> Edge cases :: 
		We need to take care of the case where a = b = 0 (degenerate case).
		There are 2 sub-cases in this ::
			1. When c = 0 = Solutions: infinite		
			2. When c!= 0 = Solutions: 0
	
	-> Extended Euclidean Algorithm can be used to find solution of the form  :: ax + by = g (g = GCD(a , b)).
	   So, to find solution of ax + by = c, first find solution of ax + by = g.
	   
	-> Let x0 and y0 are solution of equation ax + by = g then :
			Solution of equation ax + by = c will be ::
				x = x0 * (c/g)
				y = y0 * (c/g)
			Proof :: multiplu c/g on both sides LHS and RHS
	
	-> Most important condition is :: c%g == 0 then only integer solution would exist.
	
	-> Problem statement :: 
			Given a Linear Diophantine Equation, find a solution (x, y) such that x+y is "minimum" among all possible solutions.
			
	-> Final eqution type :: 
			x + y = x0 + y0 + k*((b - a)/g)
			
			-> Case 1: a < b :: Chose smallest k possible.
			-> Case 2: a > b :: Chose biggest k possible.
			-> Case 3: a = b :: Solution is always x0 + y0.
**/

int gcd(int a, int b, int& x, int& y) {
	// base case 
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	
	int x1, y1;
	int g = gcd(b, a%b, x1, y1);
	
	x = y1;
	y = x1 - y1*(a/b);
	
	return g;
}

bool find_Solution(int a, int b, int c, int &x, int &y) {
	int x0, y0;
	
	int g = gcd(abs(a), abs(b), x0, y0);
	
	if(c%g != 0) { // base case
		return false;
	}
	
	x = x0 * c/g;
	y = y0 * c/g;
	
	if(a < 0) {// because x is computed for positive abs(a) only.
		x = -x;
	}
	if(b < 0) {
		y = -y;
	}
	
	return true;
}

int main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c;
	
	if(find_Solution(a,b,c,x,y) == false) {
		cout << "No Solution exist\n";
	} else {
		cout << " x : " << x << " y : " << y;
	}
	
	return 0;
}
