// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
**/

int nb,ns,nc,pb,ps,pc,r;
int b=0, s=0, c=0;

bool check(int x) {
    int totalB = x*b, totalS = x*s, totalC = x*c;
    totalB = max(0ll,totalB - nb);
    totalC = max(0ll, totalC - nc);
    totalS = max(0ll, totalS - ns);
    int price = totalB*pb + totalS*ps + totalC*pc;
    if(price <= r) {
        return true;
    }
    return false;
    
}

void solve() {
    
    string str;
    cin >> str;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == 'B') {
            b++;
        } else if(str[i] == 'C') {
            c++;
        } else {
            s++;
        }
    }
    
	int low = 0, high = 1e15;
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(check(mid) == true) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    if(check(low) == true) {
        cout << low;
    } else {
        cout << high;
    }
        
}

signed main() {
	int tc = 1;
	//cin >> tc;
	while(tc--) {
		solve();
	}
	
	
	return 0;
}
