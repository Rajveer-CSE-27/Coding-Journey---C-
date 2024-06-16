class Solution {
public:
    int countVowelPermutation(int n) {
        long long a=1, e=1, i=1, o=1, u=1;
        int mod = 1e9 + 7;

        for(int j=2; j<=n; j++) {
            long long n_a = 0, n_e = 0, n_i = 0, n_o = 0, n_u = 0;

            n_a = (e + u + i)%mod;
            n_e = (a + i)%mod;
            n_i = (e + o)%mod;
            n_o = (i)%mod;
            n_u = (i + o)%mod;

            a = n_a;
            e = n_e;
            i = n_i;
            o = n_o;
            u = n_u;
        }
        long long ans = (a + e + i + o + u)%mod;
        return ans;
    }

};
