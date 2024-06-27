class Solution {
public:

    set<string> dict;
    string str;
    int n;
    char dp[301];

    bool fun(int i) {
        if(i == n) {
            return true;
        }
        if(dp[i] != '0') {
            if(dp[i] == '1') {
                return true;
            }
            return false;
        }

        string temp = "";
        bool ans = false;

        for(int j=i; j<n; j++) {
            temp += str[j];

            if(dict.find(temp) != dict.end()) {
                if(fun(j+1) == true) {
                    ans = true;
                }
            }
        }
        if(ans == true) {
            dp[i] = '1';
        } else {
            dp[i] = '2';
        }

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for(string t:wordDict) {
            dict.insert(t);
        }
        str = s;
        n = s.length();
        memset(dp, '0', sizeof(dp));

        return fun(0);
        

    }
};
