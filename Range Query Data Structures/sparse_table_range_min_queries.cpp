// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=iaRvydtqLV4&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=3
https://cses.fi/problemset/task/1647

-> Sparse Table :: 
		It is a 2D matrix
		table[i][j] = answer to the query : [i, i + 2^j - 1]
						 

-> How can it answer queries ? 
			  
	-> Sparse table will store :: 
			For each index i it will store value for range size :: (1,2,4,8,16,32,64,.....) starting from i.
	
	-> Range queries :: 
			Let you want answer for range :: [l,r]
			Let w = r - l + 1 that is length of the range.
			Any w can be written as sum of power of 2's. Eg if w = 45 then w = 101101 in binary
			Hence :: 45 = 2^5 + 2^3 + 2^2 + 2^0. Now we only need to see these 4 ranges for our answer.
			
			Hence any range w can be broken into <=logw ranges 
			
			Here :: sum[l,r] = table[l][5]  + table[l1][3] + table[l2][2] + table[l3][0]
							where l1 = l + 2^5
								  l2 = l1 + 2^3
								  l3 = l2 + 2^2
	
	-> How to build sparse table ::
			Using DP
			table[i][j] = table[i][j-1] + table[i + 2^(j-1), j-1]
						  [i, i + 2^(j-1) - 1] range , [i + 2^(j-1), i + 2^(j-1) + 2^(j-1) - 1] range
						  these both ranges will cover :: [i, i + 2^j - 1] range which we want
			
			Base case :: table[i][0] = vc[i];
			
	
Sparse table can answer many things like range sum, range min, range max, etc.
It depends what we add to the value of out table.
	
	-> Range Minimum Queries in O(1) time :: 
			We want to find minimum value in range :: [l,r]
			So sparse table will store :: 
						table[i][j] = minimum value in range (i, i + 2^j - 1)
				
			
			Let range [l,r] be of len = w = r-l+1.
			Find the floor(log2(w)) = x. 
			our answer = min(min(table[l][x]), min(table[r - 2^x + 1][x])).
			and these both values already present in table.
			
			Why this worked ? 
					let [l,r] :: [12,97]
					Now length = 97 - 12 + 1 = 86
					floor(log2(86)) = 6.
					
					2^6 = 64.
					
					table[12][6] = will give us minimum value in range [12,12 + 64 - 1] : [12,75]
					table[97 - 64 + 1][6] = range[34, 34 + 64 - 1] : [33,97]
					Hence we covered whole range [12,97] and answer  = min(table[12][6], table[34][6]).
					
	
	Precompute the floor(log) value for all values .
								  
								  
**/

const int N = 200001;

vector<int> vc;

int floor_log2[N];
int sparseTable[N][25];

void compute_log() {
	floor_log2[1] = 0;
	
	for(int i=2; i<N; i++) {
		floor_log2[i] = 1 + floor_log2[i/2];
	}
}

void build_sparse_table() {
	int n = vc.size();
	
	//0 based indexing in table
	for(int l= n-1; l>=0; l--) {
		for(int w=0; w<25; w++) {
			int r = l + (1<<w) - 1;
			
			if(r >= n) { // out of possible range
				break;
			}
			if(w == 0) {
				sparseTable[l][w] = vc[l]; // base case
			} else {
				sparseTable[l][w] = min(sparseTable[l][w-1], sparseTable[l + (1<<(w-1))][w-1]);
			}
		}
	}
}

int query(int l, int r) {
	
	int w = r - l + 1;
	int power = floor_log2[w];
	
	int ans = min(sparseTable[l][power], sparseTable[r - (1<<power) + 1][power]);
	return ans;
	
}

int main(){
	
	int n,q;
	cin >> n >> q;
	vc.resize(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i];
	}
	
	compute_log();
	build_sparse_table();
	
	while(q--) {
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		cout << query(l,r) << '\n';
	}
	
    return 0;
}
