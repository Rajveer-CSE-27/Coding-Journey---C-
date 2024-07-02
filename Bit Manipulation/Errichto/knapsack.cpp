// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mx = 1e6;

/**
Problem :: You are given 𝑁 ≤ 1000 items, each with some weight 𝑤𝑖. 
           Is there a subset of items with total weight exactly 𝑊≤106?
           
Approach 1 :: Knapsack problem which will have complexity : O(N * W); As it uses boolean array to keep a track of sum

Approach 2 : Use bitset instead of boolean array in knapsack. Time complexity :: O((N*W)/32)

**/


bool approach1(int n, vector<int>& weights, int W) {
    
    vector<bool> check(W+1, false);
    check[0] = true;
    
    for(int i=0; i<n; i++) {
        
        int currentWeight = weights[i];
        
        for(int j=W; j>=currentWeight; j--) {
            if(check[j - currentWeight] == true) {
                check[j] = true;
            }
        }
    }
    
    return check[W];
    
}

bool approach2(int n, vector<int>& weights, int W) {
    
    bitset<mx> b;
    b[0] = 1;
    
    for(int i=0; i<n; i++) {
        
        int currentWeight = weights[i];
        
        b = (b | (b<<currentWeight)); // this means that it will active all the bits that are obtained by sum of previous active values and currentWeight
                                      // and also keep previous active bits as it is
    }
    
    return b[W];
    
}

int main() {
    
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }
    
    int W;
    cin >> W;
    
    if(approach1(n, weights, W) == true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    if(approach2(n, weights, W) == true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
    
}
