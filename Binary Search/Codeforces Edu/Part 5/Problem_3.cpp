#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k; 
vector<int> a,b;

bool is_good(int x) {
    
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int v1 = x - a[i];
        v1--;
        auto ub = upper_bound(b.begin(), b.end(),v1);
        if(ub == b.begin()) {
            continue;
        }
        ub--;
        int index = ub - b.begin();
        index++;
        cnt += index;
    }
    
    return (cnt < k);
} 

signed main() {
    
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    
    int low = 0; // definitely a good value because cnt(0) is always less than <= k;
    int high = a[n-1] + b[n-1] + 10;// definitly a bad value.
    
    for(int i=0; i<80; i++) {
        int mid = (low + high)/2;
        
        if(is_good(mid) == true) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << low;
    
    return 0;
}
