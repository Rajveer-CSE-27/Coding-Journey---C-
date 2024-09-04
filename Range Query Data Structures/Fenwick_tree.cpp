// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**

https://www.youtube.com/watch?v=DPiY9wFxGIw

Fenwick tree also called binary indexed tree.

    Uses :: 
        -> Calculates value of a given range [l,r] in O(logn) time.
        -> Updates the value of an element in O(logn) time.
        -> Requires O(n) space to store.
        -> Easy to code.
        
    
    Finding rightmost set bit :: 
        
        Rightmost set bit of x = (x & (-x))
        Remove rightmost set bit from x :: x - (x & (-x))
        
        See video for explaination :: 
            Becuase : -x = 2's complement of x = x' + 1 

       
    NOTE :: Bit array must always be 1 indexed. Hence convert your original array to 1 indexed.
     
    Constructing the binary indexed tree array [BIT] array ::
        
        Bit[i] will store sum {we are considering sum operations here} of array elements from (j+1) --> (i)
        where j = remove rightmost setbit from i.
        Hence j = i - (i & (-i))
        
    
        Eg.  Bit[13] : 
                13 = 1101
                removing last set bit = 1100 = 12 = j
                Hence j+1 = 13
                Bit[13] will store sum from 13 to 13.
                
                
             Bit[12] : 
                12 = 1100
                removing last set bit = 1000 = 8 = j
                Hence j+1 = 9
                Bit[12] will store sum from 9 to 12.
                
         
        Every ith index of Bit array will store a partial sum.
        
        
    
    Find prefix_sum(13) : 
         sum(1,13) = bit[13] + bit[12] + bit[8]
                     [13,13] + [9,12] + [1,8]
                    
        
          prefix_sum(x) {
                int ans = 0;
                while(x > 0) {
                    ans += bit[x];
                    x = x - (x & (-x));
                }
                return ans;
          }
          
          Time complexity of prefix_sum = O(logn)
        
    Find sum_of_range(l,r) :
            int ans = prefix_sum(r) - prefix_sum(l-1)
            return ans;
    
    
    Updating value in Bit array given there is update at ith index in original array :: 
            
            Let we want to add value x to ith element i.e update ith element of original array from :: a[i] = a[i] + x
            Then in the bit array we need to update all those j's whose removal of rightmost set bit will give us i.
            That is value of a[i] would be a part of bit[j].
            
            
            Let we updated index = 13 in original array.
            
            13 = 1101
            update bit[13] 
            add 1 to last set bit of 13 = 1101 + 0001 = 1110 = 14
            update bit[14] because range of 14 would include 13
            add 1 to last set bit of 14 = 1110 + 0010 = 10000 = 16
            update bit[16] because range of 16 would include 13
            add 1 to last set bit of 16 = 10000 + 10000 = 100000 = 32
            update bit[32] ..
            ans so on..
            
        
        void update(int i, int x) {
            while(i <= N) { // N is the maximum index in array
                bit[i] += x;
                i += (i & (-i));
            }
        }
        
        Time complexity of update is O(logn).
    
    
    Constructing bit array in O(n) time :: 
        Let bit[N] be BIT array and a[N] be the array we need to initialize our BIT with.
        Notice that for all i we need to add a[i] to positions i, i + (i & -i) and so on in the bit array.
        Also, a[i + (i & -i)] will also be added to all these positions except i.
        
        void intialize() {
            for(int i=1; i<=n; i++) {
                bit[i] += a[i];
                if(i + (i & (-i)) <= n) {
                    bit[i + (i & (-i))] += bit[i];
                }
            }
        }   
        
        Total time :: O(n)
            
                                
**/

int n;
vector<int> vc;
vector<int> bit;

void initialize() {
    
    for(int i=1; i<=n; i++) {
        bit[i] += vc[i];
        if(i + (i & -i) <= n) {
            bit[i + (i & -i)] += bit[i];
        }
    }
}

int prefix_sum(int i) {
    int ans = 0;
    
    while(i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

int sum_of_range(int l, int r) {
    
    return (prefix_sum(r) - prefix_sum(l-1));
}

void update(int i, int x) {
    
    // we are updating a[i] += x in original array
    
   
    while(i <= n) { // n is the maximum index in array
        bit[i] += x;
        i += (i & -i);
    }

    
}


int main() {
    
    cin >> n;
    
    vc.resize(n+1); // 1 based for fenwick tree
    
    bit.resize(n+1, 0);
    
    //initialize();
    
    
    
    
    return 0;
}
