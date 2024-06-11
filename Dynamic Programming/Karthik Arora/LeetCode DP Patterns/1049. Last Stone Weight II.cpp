//Think of the final answer as a sum of weights with + or - sign symbols infront of each weight. Actually, all sums with 1 of each sign symbol are possible.

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> temp;
        temp.insert(stones[0]);

        for(int i=1; i<stones.size(); i++) {
            set<int> temp2;
            for(auto it:temp) {
                int val = abs(stones[i] + it);
                int val2 = abs(stones[i] - it);
                temp2.insert(val);
                temp2.insert(val2);
            }
            temp = temp2;
        }
        return *temp.begin();
    }
};
