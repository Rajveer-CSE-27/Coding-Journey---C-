class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res;

        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '#') {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        for(int i=0; i<t.length(); i++) {
            if(t[i] == '#') {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(t[i]);
            }
        }

        string res2;
        while(!st.empty()) {
            res2 += st.top();
            st.pop();
        }

        return (res == res2);
        
    }
};
