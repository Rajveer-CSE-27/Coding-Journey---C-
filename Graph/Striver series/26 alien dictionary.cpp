// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=26
https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

Topological sort
Thoda extra kaam bhi hai.

First try to make a DAG by sorted order of strings.
Edge case ko consider karna jisme tum un characters ko pehle loge jinka outdegree == 0 hoga. Ye nhi karna hai

**/


class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // making DAG graph
        bool graph[26][26];
        memset(graph, false, sizeof(graph));
        
        for(int i=1; i<n; i++) {
            int j1 = 0, j2 = 0;
            while(j1 < dict[i-1].length() and j2 < dict[i].length() and dict[i-1][j1] == dict[i][j2]) {
                j1++;
                j2++;
            }
            if(j1 < dict[i-1].length() and j2 < dict[i].length()) {
                char prev = dict[i-1][j1], curr = dict[i][j2];
                
                graph[prev - 'a'][curr - 'a'] = true;
            }
        }
        
        vector<int> indegree(26, 0), outdegree(26, 0);
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                if(graph[i][j] == true) {
                    indegree[j]++;
                    outdegree[i]++; // because wahi nodes pehle lene hai jisse edges out bhi hoti ho
                }
            }
        }
        
        queue<int> q;
        for(int i=0; i<26; i++) {
            if(indegree[i] == 0 and outdegree[i] > 0) { // indegree[i] == 0 unka bhi hoga jo hume last me lene hai apne string me
                q.push(i);
            }
        }
        
        string ans;
        vector<bool> check(k, false);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node < k) {
                ans += ('a' + node);
                check[node] = true;
            }
            
            for(int i=0; i<26; i++) {
                if(graph[node][i] == true) {
                    indegree[i]--;
                    if(indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        
        for(int i=0; i<k; i++) {
            if(check[i] == false) {
                ans += ('a' + i);
            }
        }
        return ans;
    }
    
};

int main() {
    
    
    return 0;
}
