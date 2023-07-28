#include<bits/stdc++.h>
using namespace std;

bool isPallindromeIterative(string s) {
	int n = s.length();
	int i =0 , j=n-1;
	while(i < j) {
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

bool isPallindromeRecursive(string s , int l , int r) {
	if(l >= r) return true;
	if(s[l] != s[r]) return false;
	return isPallindromeRecursive(s,l+1,r-1); 
}

int main() {
	
	string s;
	cin >> s;
	bool ans = isPallindromeIterative(s);
	cout << ans << endl;
	
	bool ans2 = isPallindromeRecursive(s , 0 , s.length()-1);
	cout << ans2 << endl;
	return 0;
}
