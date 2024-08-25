// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=O4w-aX5mSks&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=6
https://www.spoj.com/problems/FRNDCIRC/

Disjoint set data structure.
add just one more functionality of getting size of set when we input the set representative.
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
    
    int sizeOfSet(T x) {
        T representative = find(x);
        return representative_To_Set_Info[representative].first;
    }
};

void solve() {
    int n;
    cin >> n;
    
    DisjointSetDS<string> dsu;
    set<string> person;
    
    for(int i=0; i<n; i++) {
        string s1,s2;
        cin >> s1 >> s2;
        
        if(person.find(s1) == person.end()) {
            dsu.make_set(s1);
            person.insert(s1);
        }
        if(person.find(s2) == person.end()) {
            dsu.make_set(s2);
            person.insert(s2);
        }
        
        dsu.unionSet(s1,s2);
        
        cout << dsu.sizeOfSet(s1) << '\n';
    }
}

int main() {
    
    // object of Disjoint set
    //DisjointSetDS<data type> dsu;
    
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    
   
    return 0;
}
