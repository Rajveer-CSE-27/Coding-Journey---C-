class Solution {
public:
    // see kartik arora remove boxes video

    vector<int> groups;
    map<int,vector<int>> color_indices;
    vector<int> index_color;

    int dp[101][101][101];

    int fun(int startIndex, int endIndex, int extras) {
        if(startIndex > endIndex) {
            return 0;
        }

        if(dp[startIndex][endIndex][extras] != -1) {
            return dp[startIndex][endIndex][extras];
        }

        // not merge current with later valid group
        int ans = (groups[startIndex] + extras) * (groups[startIndex] + extras) + fun(startIndex + 1, endIndex, 0);

        int col = index_color[startIndex];
        vector<int> temp = color_indices[col];
        auto ub = upper_bound(temp.begin(), temp.end(), startIndex);
        int index = ub - temp.begin();

        int newGroup;
        if(index == temp.size()) {
            newGroup = endIndex + 1;
        } else {
            newGroup = temp[index];
        } 
        while(index < temp.size() and newGroup <= endIndex) {

            int val = fun(startIndex+1, newGroup-1, 0) + fun(newGroup, endIndex, extras + groups[startIndex]);

            ans = max(ans, val);

            index++;
            if(index < temp.size()) {
                newGroup = temp[index];
            }
            
        }

        return dp[startIndex][endIndex][extras] = ans;
        
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();

        int cnt = 1;
        int prevCol = boxes[0];
        for(int i=1; i<n; i++) {
            if(boxes[i] == prevCol) {
                cnt++;
            } else {
                groups.push_back(cnt);
                color_indices[prevCol].push_back(groups.size()-1);
                index_color.push_back(prevCol);
                cnt = 1;
                prevCol = boxes[i];
            }
        }
        groups.push_back(cnt);
        color_indices[prevCol].push_back(groups.size()-1);
        index_color.push_back(prevCol);

        memset(dp, -1, sizeof(dp));
        int ans = fun(0, groups.size()-1, 0);

        return ans;

    }
};
