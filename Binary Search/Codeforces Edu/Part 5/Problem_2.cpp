#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/B

Approach :: Binary search for finding the k-th ascending elements in some set.

            So for a value of n : the rows would look like ;:
                [1,2,3,.........,n]
                [2,4,6,8,.......,2*n]
                [3,6,9,.........,3*n]
                .
                .
                .
                [n, 2*n, 3*n, ........, n*n]
            
            These are n segments each having n values and we need to find the k-th value in ascending order.
            
        
        Let a variable be x which will represent a value from the given n*n values
        Let there be a function cnt(x) which will count number of values less than x.
        Now the cnt(x) function follows a good-bad sequence for a upper bound k. i.e the inequality :: cnt(x) <= k.
        The cnt(x) <= k :: will have :: 11111111100000000...... and we need to find greatest x int this.
        
        Hence use binary search for cnt(x) <= k inequality.
        
        Use technique of binary search on real numbers. Then only we get accurate results as there could be duplicate values.
        
    
**/

int n,k;

bool is_good(int x) {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        
        if(x%i == 0) {
            cnt += min(x/i - 1, n);
        } else {
            cnt += min(x/i, n);
        }
    }
    
    return (cnt < k);
} 

signed main() {
    
    cin >> n >> k;
    
    int low = 0; // definitely a good value because cnt(0) is always less than <= k;
    int high = n*n + 10;// definitly a bad value.
    
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
