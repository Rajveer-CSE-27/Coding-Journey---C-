// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=_BvEJ3VIDWw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=39
https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

BFS type solution likhna hai.
Video dekho to samaj jaoge. And BFS ache se likho bhai. Jab add karo tabhi update kar diya karo
**/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        // val, steps
        q.push({start,0});
        vector<int> steps(100000, INT_MAX);
        steps[start] = 0;
        
        if(start == end) {
            return 0;
        }
        
        while(!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();
            
            for(int x:arr) {
                int val = (1LL * x * node.first) % 100000;
                if(steps[val] <= node.second + 1) {
                    continue;
                }
                steps[val] = node.second + 1;
                if(val == end) {
                    return steps[val];
                }
                q.push({val, steps[val]});
            }
        }
        
        return -1;
    }
};




int main() {
    
    
    return 0;
}
