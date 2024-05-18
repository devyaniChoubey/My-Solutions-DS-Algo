https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    q.push({i, j});
                }else{
                    grid[i][j] = 1e9;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1,0,1,0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m) continue;

                if(grid[nRow][nCol] > grid[row][col] + 1){
                    q.push({nRow, nCol});
                    grid[nRow][nCol] = grid[row][col] + 1;
                }
            }
        }

        priority_queue<vector<int>>pq;

        
        pq.push({grid[0][0] , 0, 0});
        grid[0][0] = -1;



        while(!pq.empty()){
            vector<int>cur = pq.top();
            pq.pop();

            if(cur[1] == n-1 && cur[2] == m-1) return cur[0];

            int delRow[] = {-1,0,1,0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = cur[1] + delRow[i];
                int nCol = cur[2] + delCol[i];

                if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || grid[nRow][nCol] == -1) continue;
                
                pq.push({min(grid[nRow][nCol], cur[0]) , nRow, nCol});
                grid[nRow][nCol] = -1;
            }
        }

        return -1;
    }
};