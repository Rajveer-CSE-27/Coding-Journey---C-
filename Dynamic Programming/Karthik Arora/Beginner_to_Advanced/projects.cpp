// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**
Problem link :: https://www.cses.fi/problemset/task/1140/

Approach :: A similar approach like LIS

	-> Sort the given inputs according to finish times. Note :: {sorting acc to finish times will only give correct answers}
	-> Now form a map<int,int> mp : 
							mp[x] = y will store that best total profit that we can earn till time x is = y.
			
			Base case : mp[vc[0][1]] = vc[0][2]. That insert the first task.
			
	-> Now iterate through the array.
	-> At each iteration :: 
					Find the largest element in map which is less than start time of current index.
					Add its total profit to current task profit and insert vc[i][1] in map with value = calculated profit. {Handle the edge case where no element is less than current start time}
					
					After adding an element mp[x] = y in map. Note that if mp[x] already exist in map then check its value. if y > mp[x] then only make mp[x] = y.
					
					After adding element mp[x] = y in map check one smaller element from x. Let it be x1. If mp[x1] >= mp[x] then delete x from map. Because a smaller time with more or equal profit exists in map then why would we need mp[x] = y. That is a greater element with less profit is discarded.
					
	-> Simulate this example :: 
		10
76 77 96
77 78 11
11 12 46
43 44 82
25 25 87
96 97 4
39 40 22
42 42 62
42 42 30
88 88 19

Answer = 418.
					
**/

bool comp(vector<int> v1, vector<int> v2) {
	
	
	// sorting by finish times.
	if(v1[1] < v2[1]) {
		return true;
	}
	if(v1[1] > v2[1]) {
		return false;
	}
	if(v1[2] <= v2[2]) {
		return true;
	}
	return false;
}

signed main() {
        
    int n;
    cin >> n;
    vector<vector<int>> vc(n, vector<int>(3));
    for(int i=0; i<n; i++) {
    	cin >> vc[i][0] >> vc[i][1] >> vc[i][2];
    } 
    
    sort(vc.begin(), vc.end(), comp);
    map<int,int> mp;
    mp[vc[0][1]] = vc[0][2];
    
    for(int i=1; i<n; i++) {
    	auto lb = mp.lower_bound(vc[i][0]);
    	
    	if(lb == mp.begin()) {
    	
    		if(mp.find(vc[i][1]) != mp.end()) {
    			// if mp[x] already present in map.
    			
    			mp[vc[i][1]] = max(mp[vc[i][1]], vc[i][2]);
    		} else {
    			mp[vc[i][1]] = vc[i][2];
    		}
    		
    		// discarding the current element if any smaller element with more or equal profit exist.
    		auto it = mp.find(vc[i][1]);
    		if(it != mp.begin()) {
    			it--;
    			if(it->second >= mp[vc[i][1]]) {
    				mp.erase(vc[i][1]);
    			}
    		}
    	} else {
    		lb--;
    		int val = lb->second + vc[i][2];
    		if(mp.find(vc[i][1]) != mp.end()) {
    			mp[vc[i][1]] = max(mp[vc[i][1]], val);
    		} else {
    			mp[vc[i][1]] = val;
    		}
    		
    		// discarding the current element if any smaller element with more or equal profit exist.
    		auto it = mp.find(vc[i][1]);
    		if(it != mp.begin()) {
    			it--;
    			if(it->second >= mp[vc[i][1]]) {
    				mp.erase(vc[i][1]);
    			}
    		}
    	}
    }
    
    // give the maximum profit possible.
    int ans = 0;
    for(auto it:mp) {
    	ans = max(ans, it.second);
    }
    cout << ans;
    
    return 0;    
}
