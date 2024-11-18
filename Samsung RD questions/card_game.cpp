#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Greedily hi kar rahe hai jo next sum ko sabse zyaada improve kare

**/


 
int main() {
  
  int n,k;
  cin >> n >> k;
  
  vector<int> cardType(n), cardValue(n);
  for(int i=0; i<n; i++) {
    cin >> cardType[i];
  }
  
  for(int i=0; i<n; i++) {
    cin >> cardValue[i];
  }
  
  priority_queue<int> zero, one, two, three;
  
  for(int i=0; i<n; i++) {
    
    if(cardType[i] == 0) {
      zero.push(cardValue[i]);
      
    } else if(cardType[i] == 1) {
      one.push(cardValue[i]);
      
    } else if(cardType[i] == 2) {
      two.push(cardValue[i]);
      
    } else {
      three.push(cardValue[i]);
    }
    
  }
  
  int sm = 0;
  int z=0, o=0, t=0, th=0;
  
  for(int i=0; i<k; i++) {
    
    int increase0 = 0, increase1 = 0, increase2 = 0, increase3 = 0;
    
    if(!zero.empty()) {
      int v = zero.top();
      increase0 = (z + 1)*(z + 1) - (z)*(z);
      increase0 += v;
    }
    if(!one.empty()) {
      int v = one.top();
      increase1 = (o + 1)*(o + 1) - (o)*(o);
      increase1 += v;
    }
    if(!two.empty()) {
      int v = two.top();
      increase2 = (t + 1)*(t + 1) - (t)*(t);
      increase2 += v;
    }
    if(!three.empty()) {
      int v = three.top();
      increase3 = (th + 1)*(th + 1) - (th)*(th);
      increase3 += v;
    }
    
    
    if(increase0 > 0 and increase0 >= increase1 and increase0 >= increase2 and increase0 >= increase3) {
      sm += increase0;
      z++;
      zero.pop();
      
    } else if(increase1 > 0 and  increase1 >= increase0 and increase1 >= increase2 and increase1 >= increase3) {
      sm += increase1;
      o++;
      one.pop();
      
    } else if(increase2 >= 0 and increase2 >= increase0 and increase2 >= increase1 and increase2 >= increase3) {
      sm += increase2;
      t++;
      two.pop();
      
    } else if(increase3 >= 0){
      sm += increase3;
      th++;
      three.pop();
    }
    
  }
  
  cout << sm;
  
  return 0;
}


