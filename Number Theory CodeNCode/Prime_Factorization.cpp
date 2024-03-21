#include <bits/stdc++.h>
using namespace std;


// O(n*logi) time complexity
void approach1(int n) {
	
	if(n == 1) {
		cout << 1 << " " << 1 << '\n';
		return;
	}
	
	for(int i=2; i<=n; i++) {
		if(n%i == 0) {
			int val = i;
			int cnt = 0;
			while(n%i == 0) {
				n /= i;
				cnt++;
			}
			cout << val << " " << cnt << '\n';
		}
	}
}

//O(sqrt(n)) time complexity
void approach2(int n) {
	
	if(n == 1) {
		cout << 1 << " " << 1 << '\n';
		return;
	}
	
	for(int i=2; i*i <=n; i++) {
		if(n%i == 0) {
			int val = i;
			int cnt = 0;
			while(n%i == 0) {
				n /= i;
				cnt++;
			}
			cout << val << " " << cnt << '\n';
		}
		
	}
	// Edge case
	if(n > 1) {
		cout << n << " " << 1 << '\n';
	}
}


int main() {
	
	int n;
	cin >> n;
	
	approach1(n);
	cout << '\n';
	approach2(n);
	
	return 0;
}
