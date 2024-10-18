#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
/**
Queries and array
You are given three arrays A, B, and C of length N.
For each index i, All is greater than or equal to Bi.
You can perform the given operation on this array A as many times as you want. In each operation:
• Pick any two indices / and j and add 1 to A[l] and subtract 1 from Aff). This operation can only be done
only if Alf] is currently greater than Blj]. The cost of this single operation is C(j.
Note: 1-based indexing is used.
Task
If you perform the operations optimally, determine the maximum possible minimum number present in the
final array A and also find the minimum cost required to make this possible. As this cost can be very large,
you are supposed to find it modulo 10°+7.



Approach :: 
    Binary search on answer

**/

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mn;


bool check(int x, vector<int>& a, vector<int>& b, vector<int>& c, int& n, long long& cost) { // everytime send a new min heap
  
  // checking if x can be minimum value in the array a
  
  vector<int> vc = a;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mnHeap = mn;
 
  long long tempCost = 0ll;
  
  for(int i=0; i<n; i++) {
    
    bool flag = false;
    
    if(vc[i] < x) {
      int reqOperations = x - vc[i];
      
      while(!mnHeap.empty() and reqOperations > 0) {
        pair<int,int> pr = mnHeap.top();
        mnHeap.pop();
        
        int j = pr.second;
        
        if(j == i) {
          flag = true;
          continue;
        }
        
        int canDo = vc[j] - max(x, b[j]);
        if(canDo <= 0) {
          continue;
        }
        
        canDo = min(canDo, reqOperations);
        reqOperations -= canDo;
        
        long long op = ((canDo%mod)*(pr.first%mod))%mod;
        tempCost += op;
        tempCost %= mod;
        
        vc[j] -= canDo;
        vc[i] += canDo;
        mnHeap.push({pr.first, pr.second});
        
      }
      
      if(reqOperations > 0) {
        return false;
      }
      
    }
    
    
    
    
    if(flag == true) {
      mnHeap.push({c[i], i});
    }
    
    
    
    
  }
  
  
  cost = tempCost;
  
  return true;
}

void solve() {
  
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  
  // a[i] >= b[i]
    
  for(int i=0; i<n; i++) {
    cin >> c[i];
    mn.push({c[i], i});
  }
  
  int low = *min_element(a.begin(), a.end());
  int high = (*max_element(a.begin(), a.end())) + 1;
  
  
  // because minimum value can never exceed high
  
  int ans = low;
  long long  cost = 0ll;
  
  while(low <= high) {
    
    int mid = (low + high)/2;
    if(check(mid, a, b, c, n, cost) == true) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  
  
  cout << ans << " " << cost;
  
}


int main() {
  
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
    cout << '\n';
  }
  
  return 0;
  
}
