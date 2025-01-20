https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-01-19


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0;i < n;i++){
            pq.push({heightMap[i][0] , i, 0});
            pq.push({heightMap[i][m-1] , i, m-1});
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }

        for(int j=0;j < m;j++){
            pq.push({heightMap[0][j] , 0, j});
            pq.push({heightMap[n-1][j] , n-1, j});
            vis[0][j] = 1;
            vis[n-1][j] = 1;
        }

        int totalWaterVolume = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0, 1, 0,-1};

        while(!pq.empty()){
            int minBoundaryHeight = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || vis[nRow][nCol]) continue;

                int adjHeight = heightMap[nRow][nCol];

                if(adjHeight < minBoundaryHeight) totalWaterVolume += (minBoundaryHeight - adjHeight);

                pq.push({max(minBoundaryHeight, adjHeight) , nRow, nCol});

                vis[nRow][nCol] = 1;
            }


            
        }

        return totalWaterVolume;
    }
};