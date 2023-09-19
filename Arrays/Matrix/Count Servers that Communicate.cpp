https://leetcode.com/problems/count-servers-that-communicate/description/


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>column(n, 0) , row(m, 0);
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    column[j]++;
                    row[i]++;
                }
            }
        }

        int ans = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if((column[j] >= 2 || row[i] >= 2) && grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }
};