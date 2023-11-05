https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/description/

class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int desired = (m*n)/2;

        int low = INT_MAX, high = INT_MIN;

        for(int i=0;i < m;i++){
            low = min(low, grid[i][0]);
            high = max(high, grid[i][n-1]);
        }

        while(low <= high){
            int mid = (low + high)/2;

            int cnt = 0;

            for(int i=0;i < m;i++){
                cnt += upper_bound(grid[i].begin() , grid[i].end() , mid) - grid[i].begin();
            }

            if(cnt <= desired) low = mid+1;
            else high = mid-1;
        }

        return low;
    }
};