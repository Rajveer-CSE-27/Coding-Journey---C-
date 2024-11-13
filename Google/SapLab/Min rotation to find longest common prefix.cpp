#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

vector<int> prefix_function(string s) {
    
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    
    for(int i=1; i<n; i++) {
        
        int l = p[i-1];
        while(l > 0 and s[i] != s[l]) {
            l = p[l-1];
        }
        
        if(s[i] == s[l]) {
            l++;
        }
        p[i] = l;
        
    }
    
    return p;

}

vector<int> kmp(string s, string t) {
    
    int m = t.length();
    t += "#";
    // hash is the seperator
    vector<int> p = prefix_function(t);
    
    vector<int> occurences;
    int prev = 0;
    // here prev = p[m] which will be definitely = 0
    
    int n = s.length();
    
    for(int i=0; i<n; i++) {
        int l = prev;
        
        while(l > 0 and s[i] != t[l]) {
            l = p[l-1];
        }
        
        if(s[i] == t[l]) {
            l++;
        }
        prev = l;
        
        if(prev == m) {
            occurences.push_back(i);
        } 
    }
    
    // occurences will return the indices where string t finishes in s
    return occurences;
}




void solve() {
	
	
	string s1, s2;
	cin >> s1 >> s2;
	
	s2 += s2;
	
	int ans = -1;
	int low = 0, high = s1.length();
	
	int n = s2.length();
	n /= 2;
	
	while(low <= high) {
		
		
		int mid = (low + high)/2;
		string t = s1.substr(0, mid);
		
		vector<int> occurences = kmp(s2, t);
		
		if(!occurences.empty()) {
			
			for(int x:occurences) {
				// occurences end at index x
				
				int startIndex = x - mid + 1;
				if(startIndex >= n) {
					continue;
				}
				if(ans == -1) {
					ans = min(startIndex, n - startIndex);
				} else {
					ans = min(ans, min(startIndex, n - startIndex));
				}
			}
			
			low = mid + 1;
		} else {
			high = mid - 1;
		}
		
	}
	
	cout << ans;
	
	
}

int main() {
  
	solve();
  
  return 0;
  
}
