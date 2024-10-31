//https://leetcode.com/problems/erect-the-fence/description/


class Solution {
public:


    int orientation(vector<int> p, vector<int> q, vector<int> r) {

        //checking if r lies on left of line p->q
        
        // if slope q-r > slope p->q then return true

        if((q[1] - r[1])*(p[0] - q[0]) > (p[1] - q[1])*(q[0] - r[0])) {
            return true;
        }
        return false;

    
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();

        if(n <= 3) {
            // no matter what, all the trees will always be there on boundary
            return trees;
        }

        // sort so that leftmost points are first
        sort(trees.begin(), trees.end());

        // building the upper hull
        vector<vector<int>> upperHull;
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);

        for(int i=2; i<n; i++) {

            // at any time we are trying to check whether last 2 values can be on boundary or not       
            int sz = upperHull.size();
            while(upperHull.size() >= 2 and orientation(upperHull[sz-2], upperHull[sz-1], trees[i]) > 0) {
                // remove the last element from parameter 
                upperHull.pop_back();
                sz--;
            } 

            upperHull.push_back(trees[i]);
        }

        // building the lowerhull
        vector<vector<int>> lowerHull;
        lowerHull.push_back(trees[n-1]);
        lowerHull.push_back(trees[n-2]);

        for(int i=n-3; i>=0; i--) {
            // same thing

            int sz = lowerHull.size();
            while(lowerHull.size() >= 2 and orientation(lowerHull[sz-2], lowerHull[sz-1], trees[i]) > 0) {
                lowerHull.pop_back();
                sz--;
            }
            lowerHull.push_back(trees[i]);
        }

        // merge the upper and lower hulls unique elements

        set<vector<int>> ans;
        for(int i=0; i<upperHull.size(); i++) {
            ans.insert(upperHull[i]);
        }
        for(int i=0; i<lowerHull.size(); i++) {
            ans.insert(lowerHull[i]);
        }
        
        vector<vector<int>> vc;
        for(auto it:ans) {
            vc.push_back(it);
        }

        return vc;

    }
};
