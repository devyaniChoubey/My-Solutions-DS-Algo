https://leetcode.com/problems/grid-game/
https://leetcode.com/problems/grid-game/editorial/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long prefixSum1 = 0;
        long long prefixSum2 = 0;

        long long totalSum1 = 0;
        long long totalSum2 = 0;

        int n = grid[0].size();

        for(int i=0;i < n;i++){
            totalSum1 += grid[0][i];
            totalSum2 += grid[1][i];
        }

        long long ans = LONG_MAX;

        for(int i=0;i < n;i++){
            prefixSum1 += grid[0][i];
            ans = min(ans, max(totalSum1 - prefixSum1, prefixSum2));
            prefixSum2 += grid[1][i];
        }

        return ans;
    }
};