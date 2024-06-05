// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem link :: https://www.cses.fi/problemset/task/1145/

Appraoch :: 
        iterate the array from 1 to n;
        At any iteration the longest increasing subsequence that ends at vc[i] will be 1 + LIS that ends at index j such that j < i and vc[j] < vc[i].
        We will store LIS ending at any index i in dp[i]
        
        Hence dp[i] = 1 + max(dp[j]) where j will be iterated from 1 to i-1 and dp[j] is valid for current i iff vc[j] < vc[i].
        If none of j are valid then dp[i] = 1.
        
        This will take O(n^2) time.
        
        We will make it fast in O(nlogn) time.
        
        Observations ::
            1. If any two values x and y gives same length LIS then we will only keep smaller of them.
                That is if at any time : 7->3 and 5->3 then we keep only 5->3. Here a->b refers to that we have LIS of length 3 whose last element is a.
                
            2. Based upon the above observation we can conclude that for any vc[i] the best LIS will be given by greatest value less than vc[i].
                Because if there are two values x->l1 and y->l2 and x < y and l1 > l2 then this case is not possible. Any x < y will definitely have l1 < l2.
        
        Hence make a map<int,int> mp to store x->l.
        And for any vc[i] we will search largest value less than vc[i] in map and make dp[i] = 1 + l(of that value). And insert mp[vc[i]] = dp[i] in map.
        
        Now at any point when we fill a value x->l in map we will discard all y's in map such that y>x and ly <= lx. To keep above 2 observations working.
        
        
**/

int main() {
    
    int n;
    cin >> n;
    vector<int> vc(n), dp(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    map<int,int> mp;
    
    mp[vc[0]] = 1; // first element will always have LIS = 1 ending at first index.
    dp[0] = 1;
    
    for(int i=1; i<n; i++) {
        
        //find biggest element smaller than vc[i]
        auto lb = mp.lower_bound(vc[i]);
        
        if(lb == mp.begin()) {
            
            // if no values smalles than vc[i] then vc[i] is smallest and will have LIS = 1 ending at i
            dp[i] = 1;
            mp[vc[i]] = 1;
            auto it = mp.find(vc[i]);
            
            // delete all elements larger than vc[i] in map that have smaller than current LIS
            it++;
            while(it != mp.end() and it->second <= 1) {
                auto temp = it;
                it++;
                mp.erase(temp);
            }
            
        } else {
            lb--;
            dp[i] = 1 + lb->second;
            mp[vc[i]] = dp[i];
            auto it = mp.find(vc[i]);
            
            it++;
            while(it != mp.end() and it->second <= dp[i]) {
                auto temp = it;
                it++;
                mp.erase(temp);
            }
        }
    }
    
    // return the max element from dp.
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;    
}
