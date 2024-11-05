#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
max level sum in binary tree without using extra space
If two level have same sum then print minimum level
Level starts with 0

Approach :: morris traversal use karo and usme level ka bhi dhyan rakhte jaao

**/
struct node {
  int data;
  struct node* left;
  struct node* right;
  
  node(int x) {
    data = x;
    left = NULL;
    right = NULL;
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
    root->left = new node(2);
    
    
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(6);
    
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->right = new node(10);
    
    return root;
}

struct node *tree3() {
    
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);

    
    root->right = new node(3);
    
    return root;
}

struct node *tree4() {
    struct node *root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    
    
    return root;
}

struct node *tree5() {
    struct node *root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->right->left = new node(-30);
    root->right->right = new node(-15);
    
    
    return root;
}


int morris(struct node* root) {
  
  map<int,int> mp;
  // {level, sm}
  
  
  struct node* temp = root;
  int level = 0;
  
  while(temp != NULL) {
    
    if(temp->left == NULL) {
      
      mp[level] += temp->data;
      temp = temp->right;
      level++;
      
    } else {
      
      struct node* it = temp->left;
      
      int tempLevel = 1;
      while(it->right != temp and it->right != NULL) {
        it = it->right;
        tempLevel++;
      }
      
      
      if(it->right == NULL) {
        // first time
        mp[level] += temp->data;
        it->right = temp;
        level++;
        temp = temp->left;
      } else {
        
        // second time
        it->right = NULL;
        temp = temp->right;
        level -= tempLevel;
      }
      
    }
    
  }
  
  
  
  int ans = 0;
  int mxSm = INT_MIN;
  
  for(auto it:mp) {
    if(it.second > mxSm) {
      mxSm = it.second;
      ans = it.first;
    }
  }
  
  return ans;
  
}



int main() {
  
  cout << morris(tree1()) << '\n';
  cout << morris(tree2()) << '\n';
  cout << morris(tree3()) << '\n';
  cout << morris(tree4()) << '\n';
  cout << morris(tree5()) << '\n';
  
  
  return 0;  
}
