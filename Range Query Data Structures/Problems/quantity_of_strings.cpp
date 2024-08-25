// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**
https://www.youtube.com/watch?v=O4w-aX5mSks&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=6
https://codeforces.com/contest/150/problem/B
**/

template <class T>
class DisjointSetDS {
    unordered_map<T, T> parent;
    
    unordered_map<T, pair<int,int>> representative_To_Set_Info;
    // for each representative r it stores {size of the set of r, height of the tree with root = r}

public:
    
    // can add more functionalities as per question demands.
    
    void make_set(T x) {
        // to create a set/tree with single element
        parent[x] = x;
        representative_To_Set_Info[x] = {1,0};
        // initial set size = 1 and initial height of tree = 0
    }
    
    
    T find(T x) {
        // we will also implement path compression which will make every element's {from current node x to root} parent = set representative
        
        if(parent[x] == x) {
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(T u, T v) { // cannot use union name as it is predefined in C++
        T representative_u = find(u);
        T representative_v = find(v);
        
        if(representative_u == representative_v) {
            return;
        }
        
        // take the Set(tree) with less height and attach it to the set with greater height.
        int height_u = representative_To_Set_Info[representative_u].second;
        int height_v = representative_To_Set_Info[representative_v].second;
        
        if(height_u > height_v) {
            
            // upadate parent of reprsentative_v
            parent[representative_v] = representative_u;
            
            // update size of set of representative_u
            representative_To_Set_Info[representative_u].first += representative_To_Set_Info[representative_v].first;
            
            // note that this will not change the height_u.
            
            // erase representative_v from set of representative nodes
            representative_To_Set_Info.erase(representative_v);
        } else {
            
            parent[representative_u] = representative_v;
            representative_To_Set_Info[representative_v].first += representative_To_Set_Info[representative_u].first;
            
            // only when height_u == height_v then only height_v will increase by 1.
            if(height_u == height_v) {
                representative_To_Set_Info[representative_v].second++;
            }
            
            representative_To_Set_Info.erase(representative_u);
        }
        
    }
    
};

int power(int a, int n, int p) {
    
        
    int res = 1;
    while(n > 0) {
        if(n&1) {
            res *= a;
            res %= p;
            n--;
        } else {
            // that is square kar do
            a *= a;
            a %= p;
            n/=2;
        }
    }
    return res;
}


void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    
    DisjointSetDS<int> dsu;
    for(int i=1; i<=n; i++) {
        dsu.make_set(i);
    }
    
    for(int i=1; i<=n-k+1; i++) {
        int l = i, r = i + k - 1;
        
        while(l < r) {
            dsu.unionSet(l,r);
            l++;
            r--;
        }
    }
    
    set<int> st;
    for(int i=1; i<=n; i++) {
        st.insert(dsu.find(i));
    }
    
    int ans = power(m, st.size(), mod);
    cout << ans;
}

signed main() {
    
    // object of Disjoint set
    //DisjointSetDS<data type> dsu;
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
    }
    
   
    return 0;
}
