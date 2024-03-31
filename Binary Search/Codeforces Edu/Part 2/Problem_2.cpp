
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem Link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

Approach :: 
	All the possible answer = x(REAL NUMBER) would be divided into 2 groups ::
		-> Good :: that is for the given x we can cut atleast k pieces accross all the ropes = represented by 0
		-> Bad :: that is for the given x we cannot cut atleast k pieces accross all the ropes = represented by 1
		
	There will be one property which will be followed by x ::
		-> if current x is good then all x' less than x will definitely be good. 
		-> kyuki given length me atleast k tukde honge to usse choti length me k tukde to atleast honge hi
		
	Hence values of x will form this type of sequence ::
		-> 11111111111111110000000000000......
	
	Hence we need to find the maximum x which is good. We can use binary search for the above sequence.
	
	These types of questions that include this type of sequence can easily be solved with binary search.
	
Solution :: 
	we need to find first good x;
		Here it will be = 0 because x = 0 we can always generate as many pieces as we want of length = 0
		Therefore low = 0;
	
	**** we need to find one of the bad value to set "high" for binary search.
		according to question highest ai is 1e7 so let high = 1e8 this will make sure we cannot cut any pieces and hence this x is bad.
			

	*************************** BINARY SEARCH ON REAL NUMBERS ******************************
		if we perform mid = (l + r)/2 again and again the l and r will come close and close for real numbers.
		
		Q. What will be the stopping condition ? 
			Because there are infinite real numbers between two numbers hence stopping condition is very necessary otherwise infinite looping.
			
			-> False approach :: 
				One incorrect approach that comes to mind is :: while(r - l > 10^(-6)) because that is the precision given in question.
				But by this approach inifite looping might occur.
				Same with any value for (r-l).
			
			-> Good approach ::
				when l, r can take values till 1e9 and the set precision is approx. 10^(-5)
				then we can get the answer in about log(10^18) iterations hence approx. 60 iterations.
				For safety use 100 iterations.
				So run the binary search 100 times and you will get your answer.
				
				Time Complexity :: if time to check one value of x whether good or bad is O(n)
				then total time :: ((log(1/e)) * n) where e is the precision. hence  approx O(n)
				
	****************************************************************************************************
		

**/
int n,k;
vector<int> ropes;

bool is_good(double x) {
	int sm = 0;
	for(int i=0; i<n; i++) {
		sm += floor((double)ropes[i]/x); // that is maximum number of pieces of length x from each rope
	}
	
	return (sm >= k);
}

int main() {
	
	
	cin >> n >> k;
	ropes.resize(n);
	for(int i=0; i<n; i++) {
		cin >> ropes[i];
	}
	
	double low = 0, high = 1e8;
	
	for(int i=0; i<100; i++) {
		double mid = (low + high)/2;
		if(is_good(mid) == true) {
			low = mid;
		} else {
			high = mid;
		}
	}
	
	cout << setprecision(12) << low;
	return 0;
}
