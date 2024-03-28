
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem Link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

Approach :: 
	All the possible answer = x would be divided into 2 groups ::
		-> Good :: that is given x can hold n rectangles. = represented by 0
		-> Bad :: that is given x cannot hold n rectangles. = represented by 1
		
	There will be one property which will be followed by x ::
		-> if current x is good then x+1 will definitely be good.
		
	Hence values of x will form this type of sequence ::
		-> 000000000000011111111111111111111......
	
	Hence we need to find the minimum x which is good. We can use binary search for the above sequence.
	
	These types of questions that include this type of sequence can easily be solved with binary search.
	
Solution :: 
	we need to find first bad x;
		Here it will be = 0 because x = 0 cannot fit any rectangle hence its bad.
		Therefore low = 0;
	
	**** we need to find one of the good value to set "high" for binary search.
		We know that any square of size x can fit :: (x/a)*(x/b) rectangles.
		Hence if (x/a)*(x/b) >= n then x is good.
		
	One approach is to take directly a known good value if given. But if we take very large x then it could overflow.
	

	Another approach is to find one.
	We can find this in O(logn).
		Let us take x = 1;
		go on multiplying it with 2 till we find the first good number.
		In this way we will assure that our high will be atmost 2 times original answer.
		And to check this high we would need (2*ans)*(2*ans) = 4 * ans^2 this is close to ans and no overflow will occur.
		

**/

bool good(ll x, ll w, ll h, ll n) {
	return (x/w)*(x/h) >= n;
}

int main() {
	ll w,h,n;
	cin >> w >> h >> n;
	
	ll low = 0; // first bad
	ll high = 1;
	
	while(good(high, w, h, n) == false) {
		high *= 2;
	}
	
	while(low + 1 < high) { // yaha low + 1 karna zaruuri cause if low and high adjacent aa gaye to humesha low pe jaata rahega
		ll mid = (low + high)/2;
		if(good(mid, w, h, n) == true) {
			high = mid;
			
		} else {
			low = mid;
		}
	}
	
	cout << high;
	
	return 0;
}
