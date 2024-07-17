// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=49
https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1


Inorder successor ::
        Best Approach :: O(h) time and O(1) space
        Start with root node.
        
        
        If currentNode val <= target {
                    then this node can never be successor.
                    Hence go right to find a bigger node.
        } else {
            ans = currentNode. 
            // this can be answer but go left to find another possible answers
        }
        
        Run till you get a NULL node.
        
Inorder predecessor ::
        Similar to above approach
        
        if(currentNode val >= target) {
            go left;
        } else {
            ans = currentNode.
            go right
        }
 
**/
class Solution{
  public:
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x) {
        Node* temp = root;
        int target = x->data;
        Node* ans = NULL;
        
        while(temp != NULL) {
            if(temp->data <= target) {
                temp = temp->right;
            } else {
                ans = temp;
                temp = temp->left;
            }
        }
        return ans;
        
    }
};

class Solution{
  public:
    // returns the inorder predecessor of the Node x in BST (rooted at 'root')
    Node * inOrderPredecessor(Node *root, Node *x) {
        Node* temp = root;
        int target = x->data;
        Node* ans = NULL;
        
        while(temp != NULL) {
            if(temp->data >= val) {
                temp = temp->left;
            } else {
                ans = temp;
                temp = temp->right;
            }
        }
        
        return ans;
        
    }
};


int main() {
    return 0;
}
