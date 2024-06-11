class Solution {
public:

    vector<int> one;
    vector<int> zero;
    int s;

    vector<vector<vector<int>>> dp;

    int fun(int index, int z, int o) {
        if(index == s) {
            return 0;
        }

        if(dp[index][z][o] != 0) {
            return dp[index][z][o];
        }

        // take
        int val1 = 0;
        if(z >= zero[index] and o >= one[index]) {
            val1 = 1 + fun(index+1, z - zero[index], o - one[index]);
        }
        
        //not take
        int val2 = fun(index+1, z, o);
        int ans = max(val1, val2);
        return dp[index][z][o] = ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        s = strs.size();
        for(int i=0; i<s; i++) {
            string str = strs[i];
            int o=0, z=0;
            for(int j=0; j<str.length(); j++) {
                if(str[j] == '0') {
                    z++;
                } else {
                    o++;
                }
            }
            one.push_back(o);
            zero.push_back(z);
        }
        dp.resize(s, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        int ans = fun(0,m,n);

        return ans;

    }
};
