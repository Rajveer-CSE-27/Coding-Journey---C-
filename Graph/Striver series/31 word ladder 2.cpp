// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=AD4SFl7tu7I&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=31
https://www.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
https://leetcode.com/problems/word-ladder-ii/submissions/1381112480/

Previous question se thodi hi extra mehnat karni hai.
Reverse me BFS call kardo to kaam ho jaega

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

    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        // code here
        
        vector<vector<string>> answer;
        
        if(startWord.length() != targetWord.length()) {
            return answer;
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
            return answer;
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
        
        // yaha tak same tha
        
        vector<vector<int>> ans;
        vector<int> one(1);
        one[0] = dest;
        ans.push_back(one);
        int len = dist[dest];
        
        while(len--) { // reverse me BFS laga diya
            vector<vector<int>> tempAns;
            for(auto it:ans) {
                vector<int> temp = it;
                int last = temp[temp.size() - 1];
                for(int adj:graph[last]) {
                    if(dist[adj] == len) {
                        vector<int> temp2 = temp;
                        temp2.push_back(adj);
                        tempAns.push_back(temp2);
                    }
                }
            }
            ans = tempAns;
        }
        
        for(auto it:ans) {
            vector<int> temp = it;
            vector<string> tempo;
            for(int i=temp.size()-1; i>=0; i--) {
                tempo.push_back(wordList[temp[i]]);
            }
            answer.push_back(tempo);
        }
        
        return answer;
        
        
    }
};


int main() {
    
    
    return 0;
}
