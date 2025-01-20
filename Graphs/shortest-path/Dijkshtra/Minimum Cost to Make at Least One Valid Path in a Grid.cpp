https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/?envType=daily-question&envId=2025-01-18

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

        vector<vector<int>>cost(n, vector<int>(m, 1e9));

        cost[0][0] = 0;
        pq.push({0, 0, 0});

        int delRow[] = {0,0,0,1,-1};
        int delCol[] = {0,1,-1,0,0};
        
        while(!pq.empty()){
            int curCost = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];

            pq.pop();

            for(int i=1;i <= 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= n || nCol >= m || nRow < 0 || nCol < 0) continue;

                int minCost = 0;

                if(grid[row][col] != i) minCost++;

                if(cost[nRow][nCol] > cost[row][col] + minCost){
                    cost[nRow][nCol] = cost[row][col] + minCost;
                    pq.push({cost[nRow][nCol], nRow,nCol});
                }
            }
        } 

        return cost[n-1][m-1];
    }
};