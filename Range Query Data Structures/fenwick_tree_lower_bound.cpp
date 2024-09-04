// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**

https://www.youtube.com/watch?v=nuUspQ7ORXE
https://codeforces.com/blog/entry/61364

Binary lifting on bit array to find lower bound

    Lower_bound(x) :: will return the index i such that prefix sum from (1 to i) will be lower_bound of x 
    Time :: O(logn)
    
    see video you will understand better.
                               
**/

int n;
vector<int> vc;
vector<int> bit;

void initialize() {
    
    for(int i=1; i<=n; i++) {
        bit[i] += vc[i];
        if(i + (i & -i) <= n) {
            bit[i + (i & -i)] += bit[i];
        }
    }
}

int prefix_sum(int i) {
    int ans = 0;
    
    while(i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

int sum_of_range(int l, int r) {
    
    return (prefix_sum(r) - prefix_sum(l-1));
}

void update(int i, int x) {
    
    // we are updating a[i] += x in original array
    
   
    while(i <= n) { // n is the maximum index in array
        bit[i] += x;
        i += (i & -i);
    }

}

int lower_bound(int x) {
    
    int pos = 0, ans = 0, prevSm = 0;
    
    for(int i = log2(n); i>=0; i--) { // 2^a, 2^(a-1), 2^(a-2), .... 2^1, 2^0
        if(pos + (1<<i) <= n and bit[pos + (1<<i)] + prevSm < k) {
            pos += (1<<i);
            prevSm += bit[pos];
        }
    }
    
    return (pos + 1); //+1 because pos will have position of largest value less than x and lowerbound me >= x chahiye
}


int main() {
    
    cin >> n;
    
    vc.resize(n+1); // 1 based for fenwick tree
    for(int i=1; i<=n; i++) {
        cin >> vc[i];
    }
    
    bit.resize(n+1, 0);
    
    
    initialize();
    
    
    
    
    return 0;
}
