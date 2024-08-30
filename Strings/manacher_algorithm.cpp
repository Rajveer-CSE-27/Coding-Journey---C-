// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Manacher algorithm :: 
    
    https://leetcode.com/problems/longest-palindromic-substring/
    To find all longest pallindromic substring in O(n)
    
    https://www.youtube.com/watch?v=ei7qghJEj4Y
    Must see
    https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
    Read article about explaination of p array
    
    We can notice that every iteration of trivial algorithm increases  r  by one.
    Also  r  cannot be decreased during the algorithm. So, trivial algorithm will make  O(n) iterations in total.


**/

vector<int> p;
// p[i] will store length of longest pallindrom whose center is at p[i]

string build_hash_string(string s) {
    int n = s.length();
    string t;

    for(char c:s) {
        t += "#";
        t += c;
    }
    t += "#";

    return t;
}

void run_manacher(string s) {
    int n = s.length();
    p.resize(n, 1);

    int left = 1, right = 1;
    for(int i=1; i<n; i++) {
        p[i] = min(1, max(right - i, p[left + right - i]));

        while((i + p[i] < n) and (i - p[i] >= 0) and (s[i - p[i]] == s[i + p[i]])) {
            p[i]++;
        }
        if(i + p[i] > right) {
            left = i - p[i];
            right = i + p[i];
        }
    }
    
    // p[i] will store length of longest pallindrom whose center is at p[i]

}

string get_longest_pallindrome(string s) {

    int n = s.length();
    int mxLen = -1, centre = -1;
        
    for(int i=0; i<n; i++) {
            
        if(i&1) {
            // this location is present in original string
            //p[i] here will always be even
            int len = p[i]/2;
            if(len > mxLen) {
                mxLen = len;
                centre = i;
            }
        } else {
            // this location is not present in original string
            //p[i] here will always be odd
            int len = p[i]/2;
            if(len > mxLen) {
                mxLen = len;
                centre = i;
            }
        }
    }
        
    if(centre&1) {
        // include the centre once
        char temp = s[centre];
        string res = "";
        res += temp;
        int j = 2;
            
        mxLen--;
        while(mxLen--) {
            char c = s[centre + j];
            res += c;
            res = c + res;
            j += 2;
        } 
            
        //cout << res << '\n';
        return res;
    } else {
        string res = "";
        int j = 1;
            
        while(mxLen--) {
            char c = s[centre + j];
            res += c;
            res = c + res;
            j += 2;
        }
        //cout << res << '\n';
        return res;
    }
        
}

string longestPalindrome(string s) {
    // manacher
    string t = build_hash_string(s);
    run_manacher(t);

    return get_longest_pallindrome(t);
}


int main() {
    
    
    return 0;
}

