#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.geeksforgeeks.org/minimum-difference-between-the-highest-and-the-smallest-value-of-mines-distributed/

Read problem statement carefully.
Follow the steps as mentioned in solution.

Classic recursion problem

**/

int fun(int partitions, int index, vector<int> assigned, vector<int>& mines) {
	
	if(partitions == 0) {
		// no more partitions left to do
		
		vector<int> vc; // actual sum for each partition
		
		for(int i=0; i<assigned.size() - 1; i++) {
			int val = assigned[i] - assigned[i+1];
			vc.push_back(val);
		}
		vc.push_back(assigned[assigned.size() - 1]);
		
		int ans = *max_element(vc.begin(), vc.end()) - *min_element(vc.begin(), vc.end());
		
		return ans;
	}
	
	if(index < partitions) {
		// we need to compulsory take this
		
		assigned.push_back(mines[index]);
		
		return fun(partitions - 1, index - 1, assigned, mines);
	}
	
	// we may or may not take this
	assigned.push_back(mines[index]);
	int val1 = fun(partitions - 1, index - 1, assigned, mines);
	assigned.pop_back();
	int val2 = fun(partitions, index - 1, assigned, mines);
	
	return min(val1, val2);
	
}

int main() {   

	int n, m;
	cin >> n >> m;
 	
 	vector<int> mines(m);
 	for(int i=0; i<m; i++) {
 		cin >> mines[i];
 	}
 	
 	// prefix sum 
 	for(int i=1; i<m; i++) {
 		mines[i] += mines[i-1];
 	}
 	
 	vector<int> assigned;
 	assigned.push_back(mines[m-1]);
 	
 	int ans = fun(n - 1, m - 2, assigned, mines);
 	cout << ans;
 	
    return 0;
}
