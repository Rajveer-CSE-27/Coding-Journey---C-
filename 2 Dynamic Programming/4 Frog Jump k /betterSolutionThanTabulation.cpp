/**
Problem Statement : This is a follow-up question to “Frog Jump”. 
                    In the previous question, the frog was allowed to jump either one or two steps at a time. 
                    In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
                    If K=4, the frog can jump 1,2,3, or 4 steps at every index.

Approach :  We will try to save space beyond tabulation solution.


Time Complexity = O(n * k) because for each index we will be iterating to all possible k previous indices to get minimum jump.
Space Complexity = O(k) : just store previous k values at any time. From these k values we can get required ans for current stair.
                `   It is beneficial for smaller values of k, but not much benefecial for values of k near to n.

**/
