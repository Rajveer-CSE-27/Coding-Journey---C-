// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1371661340/

Trie also called Prefix tree ::     
    
    It is a tree like data structure used for storing strings.
    Commonly used for efficient storage and retrieval of strings.
    It supports functions like insertion, search, prefixSearch, deletion efficiently.
    
Let us implement insert, search, prefixSearch in Trie. 
Must watch the video.
                 
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
    
    bool search(string word) {
        // returns true if and only if word exists in the set of strings represented by trie
        
        int i = 0;
        TrieNode* temp = root;
        
        while(i < word.length()) {
            int index = word[i] - 'a';
            
            if(temp->contains(index) == false) {
                return false;
            }
            temp = temp->getNextTrieNode(index);
            i++;
        }
        
        // we have traversed whole word. Now if flag == true then this word is present else not
        return temp->flag;
        
    }
    
    bool startsWith(string prefix) {
        
        // similar to search but do not include last condition
        
        int i = 0;
        TrieNode* temp = root;
        
        while(i < prefix.length()) {
            int index = prefix[i] - 'a';
            
            if(temp->contains(index) == false) {
                return false;
            }
            temp = temp->getNextTrieNode(index);
            i++;
        }
        return true;
    }
    
    
};


int main() {
    
    Trie trie;
    
    trie.insert("apple");
    cout << trie.search("apple") << '\n';
    cout << trie.search("app") << '\n';
    cout << trie.startsWith("app") << '\n';
    trie.insert("app");
    cout << trie.search("app") << '\n';
    
    
    return 0;
    
    
}
