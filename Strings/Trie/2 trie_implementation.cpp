// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=2
https://www.naukri.com/code360/problems/implement-trie_1387095?count=25&search=&sort_entity=order&sort_order=ASC

Implement the insert, countWordsEqualTo, countWordsStartingWith, erase function in Trie.

We will slightly change the implementation of our TrieNode
instead of bool flag we will keep :: 
        int cw = 0; // this will keeep the count of words ending at this TrieNode
        int cp = 0; // this will keep count of all prefixes of words till this TrieNode
         

**/

struct TrieNode {
    
    int cw = 0;
    int cp = 0;
    
    TrieNode* arr[26] = {NULL};
    
    bool contains(int i) {
        return (arr[i] != NULL);
    }
    
    void add(int i) {
        arr[i] = new TrieNode();
    }
    
    TrieNode* getNextTrieNode(int i) {
        return arr[i];
    }
};


class Trie {
    
    TrieNode* root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            
            if(temp->contains(index) == false) {
                temp->add(index);
            }
            
            // go to next TrieNode
            temp = temp->getNextTrieNode(index);
            
            // NOTE :: hum next TrieNode ki hi values ke saath temper karte hai in Trie. Not with the current TrieNode.
            // i.e uss TrieNode me values ko alter karte hai jahaan word khatam hone ke baad hum pohoch rahe hai, naaki waha jaha word khatam hua hai
            
            // increment the cp of current TrieNode
            temp->cp++;
        }
        
        // at the end increment the cw of current TrieNode
        temp->cw++;
    }
    
    int countWordsEqualTo(string word) {
        
        // hence we need to return cw of the TrieNode where the word ends.
        // if word do not exist in trie then return 0
        
        TrieNode* temp = root;
        int i = 0;
        while(i < word.length()) {
            int index = word[i] - 'a';
            
            if(temp->contains(index) == false) {
                return 0;
                // trie do not contain this word at all
            }
            temp = temp->getNextTrieNode(index);
            
            i++;
        }
        
        return temp->cw;
    }
    
    int countWordsStartingWith(string word) {
        
        // hence we need to return cp of the TrieNode where the word ends.
        
        // if no prefix of any string contains this word then return 0
        
        TrieNode* temp = root;
        int i = 0;
        while(i < word.length()) {
            int index = word[i] - 'a';
            
            if(temp->contains(index) == false) {
                return 0;
            }
            temp = temp->getNextTrieNode(index);
            i++;
        }
        
        return temp->cp;
    }
    
    void erase(string word) {
        
        if(countWordsEqualTo(word) == 0) {
            return;
        } 
        
        // exactly opposite to insert.
        // go on decreementing cp till the word ends and at last decrement cw
        
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            
            // this will always exists
            temp = temp->getNextTrieNode(index);
            temp->cp--;
        }
        
        temp->cw--;
        
        /** 
        This is optional. Ho sake to avoid karna.
        if(temp->cp == 0 ) {
                delete cp;
        }
        **/
        
    }
    
};


int main() {
    
    
    Trie trie;
    
    trie.insert("samsung");
    trie.insert("samsung");
    trie.insert("vivo");
    trie.erase("vivo");
    cout << trie.countWordsEqualTo("samsung") << '\n';
    cout << trie.countWordsStartingWith("vi") << '\n';
    
    return 0;
    
    
}
