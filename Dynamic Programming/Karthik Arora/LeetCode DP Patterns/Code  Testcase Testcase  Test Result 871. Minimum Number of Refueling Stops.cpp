
// NOT a DP approach that will take O(n^2) . Define dp[i] = maximum distance we can reach by fueling i times. And find smallest i such that dp[i] >= target

// this aproach uses MAX Heap  : Time O(nlogn)
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        if(startFuel >= target) {
            return 0;
        }

        int prevMaxDist = startFuel;
        for(int fill=1; fill <= stations.size(); fill++) {
            
            int i=fill-1;
            int nextMaxDist = 0;
            while(i<stations.size() and stations[i][0] <= prevMaxDist) {
                nextMaxDist = max(nextMaxDist, stations[i][1]);
                i++;
            }
            if(nextMaxDist == 0) {
                return -1;
            }
            prevMaxDist += nextMaxDist;
            if(prevMaxDist >= target) {
                return fill;
            }
        }
        return -1;
}
