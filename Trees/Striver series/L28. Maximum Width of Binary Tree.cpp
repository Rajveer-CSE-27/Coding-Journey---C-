// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=28

See video for explaination of width.
Approach :: 
    Do BFS.
    Find distance between first node and last node in queue at each level. 
    Max distance out of all levels is answer.

https://leetcode.com/problems/maximum-width-of-binary-tree/description/
Use unsigned long long for solving leetcode problem.

**/

struct node {
    int data;
    struct node *left;
    struct node *right;
    
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct node *tree1() {
	struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    
    root->right = new node(3);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);
    
    
    return root;
}
struct node *tree2() {
    
    struct node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(3);
    
    root->right = new node(2);
    root->right->right = new node(9);    
    
    return root;
}

struct node *tree3() {
    
    struct node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(5);
    root->right = new node(2);
    return root;
}

struct node *tree4() {
    
    struct node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(5);
    root->left->left->left = new node(7);
    
    root->right = new node(2);
    root->right->right = new node(4);
    root->right->right->right = new node(6);
    
    return root;
}

int max_width(struct node *root) {
    
    queue<pair<struct node*, int>> q;
    q.push({root, 1});
    
    int ans = 1;
    
    while(!q.empty()) {
        
        int n = q.size();
        
        while(n--) {
            pair<struct node*, int> pr = q.front();
            q.pop();
            
            if(pr.first->left != NULL) { // left child index
                q.push({pr.first->left, 2*pr.second - 1});
            }
            if(pr.first->right != NULL) { // right child index
                q.push({pr.first->right, 2*pr.second});
            }
        }
        
        if(!q.empty()) {
            int temp = q.back().second - q.front().second + 1;
            ans = max(ans, temp);
        }
        
    }
    
    return ans;
}

int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    struct node *root3 = tree3();
    struct node *root4 = tree4();
    
    cout << max_width(root1) << '\n'; 
    cout << max_width(root2) << '\n'; 
    cout << max_width(root3) << '\n'; 
    cout << max_width(root4) << '\n'; 
    

    return 0;
}
