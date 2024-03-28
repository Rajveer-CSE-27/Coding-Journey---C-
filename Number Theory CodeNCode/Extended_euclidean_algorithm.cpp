#include <bits/stdc++.h>
using namespace std;

/**
Extended Euclidean Algorithm :: 
	-> Problem statement type :: 
		Given 2 integers a and b, find solution (x, y) of the equation ax + by = GCD(a,b)
	
	-> Example ::
		Let a = 57, b = 81
		Steps of euclidean while performing gcd(a,b) :: 
			81 = 1*(57) + 24
			57 = 2*(24) + 9
			24 = 2*(9) + 6
			9 =  1*(6) + 3
			6 =  2*(3) + 0
		
		Reverse these steps to get required (x,y) :: 
			Start from second last step : 
				3 = 9 - 1*(6)
				3 = 9 - 1*(24 - 2*(9)) = 3*(9) - 24
				3 = 3*(57 - 2*(24)) - 24 = 3*(57) - 7*(24)
				3 = 3*(57) - 7*(81 - 1*(57)) = 10*(57) - 7*(81)
				
				gcd(a,b) = x*a + y*b
				
				here gcd(57,81) = 3 = 10*(57) + (-7)*(81)
				hence x = 10, y = -7
				SOLVED
		
	-> Concept algorithm :: 
		let two variables : xi, yi for each iteration i in gcd : gcd(a,b) = ai*xi + bi*yi
		GCD(81, 57)			(a, b)								3 = 81x4 + 57y														
		
		GCD(57, 24)			(a1, b1) : a1 = b 					3 = 57x + 24y
									   b1 = a % b
		GCD(24, 9)												3 = 24x + 9y			

		GCD(9, 6)												3 = 9x + 6y
		
		GCD(6, 3)												3 = 6x + 3y

		GCD(3, 0)												3 = 3x + 0y
		
		In base case a = gcd, b = 0
					gcd = gcd.x + 0.y
					hence solution :: (1,0)
					
		In remaining cases :: 
			Let's take 2 consecutive function calls : 
				Let in equation 1							Let in equation 2
				Constants are : a & b 						Constants are : a1 & b1
				Coefficients : x& y 						Coefficients : x1 & y1
				Equation : ax + by = g 						Equation : a1.x1 + b1.y1 = g
				
				
			hence :: b.x1 + (amodb).y1 = g because for gcd(a,b) next call is gcd(b,a%b)
			also :: amodb = a - (floor(a/b) * b)
			hence ::  g = a.y1 + b.(x1 - y1*(floor(a/b)))
			that is the previous equation :: g = ax + by
			
			hence // main recursion formula  : x = y1
				  							   y = (x1 - y1*(floor(a/b)))
				  
			therefore we get results from solving next equations.			

**/


// clubbing this with euclidean gcd formula
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

int main() {
	
	int a=81, b=57, x,y;
	int g = gcd(a,b,x,y);
	
	cout << "GCD : " << g << " x : " << x << " y : " << y;
	return 0;
}
