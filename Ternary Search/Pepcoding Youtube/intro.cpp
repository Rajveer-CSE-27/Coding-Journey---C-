#include <bits/stdc++.h>
using namespace std;


/**

    -> Basic definition :: Take a problem. Find one-third part of Space of solution that will not give the answer. Eliminate that space.
                        
                        T(n) = T(2n/3) + O(1) = O(logn) with base = 3.
                        
    -> Time complexity comparision with binary search ::
            If we are given an increasing function or array.
            Then binary search will take ;: (1*log2(n) + 1) time because at each time we will compute only 1 mid and call f(mid)
            THe ternary search will take :: (2*log3(n) + 1) time because at each time we will compute f(c) and f(d) to check the answer.
            
            Hence time complexity of Binary Search < Ternary search. ********************************
            
    -> Ternary Search used for unimodal function :
        
        -> Unimodal function :: A function f(x) is unimodal in interval [l,r] if :: 
                                1. The function strictly increases first, reaches a maximum (at a single point or over an interval), and then strictly decreases.
                                                                            OR
                                2. The function strictly decreases first, reaches a minimum, and then strictly increases.
                                
        -> The task is to find the maximum of function  f(x) on the interval [l,r].
                :: Note : to calculate minimum value for minimum unimodal function use :: -f(x)
                
    
        -> Algorithm :: Consider finding the MAXIMUM Value
        
                -> Consider 2 points :: m1, m2 :: l < m1 < m2 < r
                -> Find the values :: f(m1) and f(m2)
                
                -> Case 1:
                        f(m1) < f(m2) : This means there is a greater value after m1 hence our answer do not lie in range :: [l,m1]
                                        Hence try to search in [m1,r] interval
                    
                    Case 2:
                        f(m1) > f(m2) : This means there is a greater value before m2 hence our answer do not lie in range :: [m2,r]
                                        Hence try to search in [l,m2] interval
                    
                    Case 3:
                        f(m1) == f(m2) : We observe that this is only possible when maximum is between [m1,m2]
                                        Hence try to search in [m1,m2] interval
                                        
                
                -> In ternary search for given [l,r] choose :: 
                                m1 = l + (r-l)/3
                                m2 = r - (r-l)/3
                                
                -> Converge till the difference between l,r > epsilon.
                -> Eopsilon is the perimiter that we set.
                
            Hence we find the max value of the function in O(log3(n)) time.                    

**/


int main() {
    
    
    
    return 0;
}
