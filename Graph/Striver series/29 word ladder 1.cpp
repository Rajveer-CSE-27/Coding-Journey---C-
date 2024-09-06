// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=tRPda0rcf8E&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=29
https://www.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

Bass undirected unweigthed graph banane tak sochna tha.
Uske baad to sirf source se destination ke beech shortest path hi find karna tha.
Also handle some edge cases.

**/

class Solution {
public:

    bool check(string s1, string s2) {
        // returns true if 1 character is distinct
        int cnt = 0;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        return (cnt == 1);
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        if(startWord.length() != targetWord.length()) {
            return 0;
        }
        
        bool flag = false, flag2 = false;
        int n = wordList.size();
        for(int i=0; i<n; i++) {
            if(wordList[i] == startWord) {
                flag = true;
            }
            if(wordList[i] == targetWord) {
                flag2 = true;
            }
        }
        
        if(flag2 == false) {
            return 0;
        }
        if(flag == false) {
            n++;
            wordList.push_back(startWord);
        } 
        
        
        vector<vector<int>> graph(n);
        // undirected unweighted graph
        
        for(int i=0; i<n; i++) { // small n
            for(int j=i+1; j<n; j++) {
                if(j != i) {
                    if(check(wordList[i], wordList[j]) == true) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }
        
        int src, dest;
        for(int i=0; i<n; i++) {
            if(wordList[i] == startWord) {
                src = i;
            }
            if(wordList[i] == targetWord) {
                dest = i;
            }
        }
        
        // find shorest path from src to dest
        vector<int> dist(n,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        
        while(!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();
            
            for(int adj:graph[node.first]) {
                if(dist[adj] == -1) {
                    q.push({adj, node.second + 1});
                    dist[adj] = node.second + 1; // BFS me hamesha ye isi time pe add karo
                } else if(dist[adj] > node.second + 1) {
                    q.push({adj, node.second + 1});
                    dist[adj] = node.second + 1;
                }
            }
        }
        
        return (dist[dest] + 1);
    
    }
};


int main() {
    
    
    return 0;
}
