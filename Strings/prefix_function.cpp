// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/**

https://www.youtube.com/watch?v=nJbNe0Yzjhw
Must watch it. VVGood video

Prefix function definition :: 
    
    Let there be a string s of length = n.
    Prefix function on string s will give us an array of length = n where 
                p[i] = v
            where v = (length of longest proper prefix = proper suffix ending at i)
            
    Proper prefix means any prefix which is not equal to string itself.
    Hence p[0] = 0 always.

Example :: 
    let s = b a b a b a c b b a 
    Note :: space sirf demo ke liye hai. Not the part of the string.
    
    so  p = 0 0 1 2 3 4 0 1 1 2
    
    p[3] = 2 because :: ba is longest proper prefix which is a proper suffix ending at index 3.
    
Brute force algorithm :: 
        O(n^3)
        You can do it yourself.

Prefix function algorithm time complexity :: 
        O(n)

Important observation :: 
        p[i+1] <= p[i] + 1
        
        Proof :: 
                longest proper prefix which is a suffix at (i+1) could be atmost 1 greater than that at (i).
                You can see that by taking examples and also p[i] >= p[i+1] - 1
        
        Hence 
        if(s[i] == s[p[i-1]]) {
               p[i] = p[i-1] + 1 
        }
        
        See video 10:00 for explaination
        
        
if(s[i] != s[p[i-1]]) then :: 
        Let p[i-1] = l
        Hence p[i] cannot be equal to l+1 now
        Now we find the greatest value k < l such that
                     prefix of length = k and suffix of length = k ending at index (i-1) are equal
                     Also s[i] == s[k]
                     
                     Then p[i] = k + 1;
                     
        If there exists a valid k then :: 
                     prefix of length = k and suffix of length = k ending at index (i-1) are equal.
                     But we already know prefix of length = l and suffix of length = l ending at index(i-1) are equal.
                     
                     Hence if we observe the prefix of length = l only :: 
                                Then inside that prefix, 
                                            The prefix of length = k and suffix of length = k ending at index(l-1) will be equal.
                                            Becuase suffix of length = k ending at index (l-1) will be equal to suffix of length = k ending at index(i-1)
                                            
                    Hence the longest k would then be p[l-1]
                    And if s[i] == s[k]
                            the p[i] = p[k-1] + 1
                            
                    else again find the next k = p[k-1] until you get 0 or find a valid k
            
        See 12:00 for best explaination
        

**/

vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    
    for(int i=1; i<n; i++) {
        
        int l = p[i-1];
        while(l > 0 and s[i] != s[l]) {
            l = p[l-1];
        }
        
        if(s[i] == s[l]) {
            l++;
        }
        p[i] = l;
        
    }
    
    return p;
    
/**
This function take O(n) time only
Proof :: 
    The outer loop runs for O(n) times
    
    The inner while loop as a whole will run for total n times only during whole time.
    
    Because we know :: p[i+1] <= p[i] + 1
    
    If p[i] = x and p[i+1] goes to a very low value let = 0
    Then to come back again to p[j] = x it would need atleast x iterations in the outer loop.
    Becuase every time we can increase by 1 only.
    
    See 18:00
     
**/

}

int main() {
    
    
    return 0;
}
