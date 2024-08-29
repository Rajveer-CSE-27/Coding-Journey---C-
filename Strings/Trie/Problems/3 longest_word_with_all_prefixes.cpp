// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
   https://www.youtube.com/watch?v=AWnBa91lThI&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=3
   https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
   
   Trie
   DFS  

**/

struct TrieNode {
    
    bool flag = false;
    /** if(flag == true) then this TrieNode marks the end of a valid word. 
        if(flag == false) otherwise
    **/
    
    TrieNode* arr[26] = {NULL};
    /**
        This array contains pointers of type TrieNode
        arr[i] represents the pointer to the next TrieNode if you are currently at ith character in current TrieNode.
    **/
    
    // these functions are added when we implement insert
    bool contains(int i) {
        return (arr[i] != NULL);
    }
    
    void add(int i) {
        arr[i] = new TrieNode();
    }
    
    TrieNode* getNextTrieNode(int i) {
        return arr[i];
    }
    
    void markTrue() {
        flag = true;
    }
};

class Trie {
    
    TrieNode* root; // each Trie data structure will have a root node
public:
    
    Trie() {
        root = new TrieNode();
        // we construct a new TrieNode whenever we start filling a Trie.
    }
    
    void insert(string word) {
        // this function inserts this word in Trie.
        // if word already exists then nothing will change by adding the word again
        
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            
            // if the current TrieNode do not contain the current character c then add it
            if(temp->contains(index) == false) {
                temp->add(index);
            }
            
            // go to next trieNode
            temp = temp->getNextTrieNode(index);
        }
        
        // mark the flag of currentTrieNode = true as we added whole word
        temp->markTrue();
    }
    
    string ans = "";
    
    void dfs(TrieNode* temp, string s) {
        
        bool canMoveForward = false;
        // we will only move to nextTrie if flag of that trie = true.
        // this indicates that a word has finished there.
        
        for(int i=0; i<26; i++) {
            if(temp->contains(i) == true) {
                TrieNode* temp2 = temp->getNextTrieNode(i);
                
                if(temp2->flag == true) {
                    canMoveForward = true;
                    char c = 'a' + i;
                    string t = s + c;
                    dfs(temp2, t);
                }
            }
        }
        
        if(canMoveForward == false) {
            if(s.length() > ans.length()) {
                ans = s;
            }
            // else we would have encountered smaller lexiographic string already
        }
        
    }
    
    string fun() {
        
        dfs(root, "");
        
        
        return ans;
    }
    
};

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        Trie trie;
        for(int i=0; i<words.size(); i++) {
            trie.insert(words[i]);
        }
        
        string ans = trie.fun();
        
        return ans;
    }
};

int main() {
    return 0;
}
