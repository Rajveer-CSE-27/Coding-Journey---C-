// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem :: There are 𝑁≤5000 workers. 
           Each worker is available during some days of this month (which has 30 days).
           For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability.
           You need to assign an important project to two workers but they will be able to work on the project only when they are both available.
           Find two workers that are best for the job — maximize the number of days when both these workers are available.     
           
Approach :: use bitset<30> for each worker.
            Iterate through all pairs of workers and find the highest number of set bits in AND of bitsets of 2 workers.
            That will be our answer.
            
            
            use b.count() which work in O(1) for counting set bits.
            And each bitwise operation AND  will take O(30/32) or O(30/64). Because size of bitset is 30
            
time complexity :: O(n*n*t) where t is O(30/32) or O(30/64). Much faster than if we store 30 values each time then complexity would be O(n*n*30)
**/


int main() {
    
    
    int n;
    cin >> n;
    bitset<30> workers[n];
    
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        
        while(m--) {
            int day;
            cin >> day;
            workers[i].set(day);
        }
    }
    
    int mx = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // find set bits in intersection
            bitset<30> intersection = (workers[i] & workers[j]);
            int val = intersection.count();
            mx = max(mx, val);
        }
    }
    
    cout << mx;
    
    return 0;
    
}
