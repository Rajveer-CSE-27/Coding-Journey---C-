class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;

        for(int i=3; i<=n; i++) {
            int temp = b;
            b = b + a;
            a = temp;
        }

        if(n == 1) {
            return a;
        } 
        return b;
    }
};
