#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**

range query.
prefix sm and preprocessing

**/

int arr[N];

void preprocessing() {
  
  memset(arr, 0, sizeof(arr));
  
  for(int i=1; i<N; i++) {
    int val = i;
    int temp[10] = {0};
    
    
    while(val > 0) {
      temp[val%10]++;
      val /= 10;
    }
    
    bool flag = true;
    
    for(int j=0; j<10; j++) {
      if(temp[j] > 1) {
        flag = false;
        break;
      }
    }
    if(flag == true) {
      arr[i] = 1;
    }
  }
  
  
  
  int sm = 0;
  for(int i=1; i<N; i++) {
    sm += arr[i];
    arr[i] = sm;
  }
  
}

void solve() {
  int n,m;
  cin >> n >> m;
  
  int ans = arr[m] - arr[n-1];
  cout << ans;
  
  
}

int main() {
  
  
  preprocessing();
  int tc;
  cin >> tc;
  while(tc--) {
    
    solve();
    cout << '\n';
    
  }
    
    
  return 0;
}
