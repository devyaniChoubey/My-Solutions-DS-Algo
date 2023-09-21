https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>minDist(n , vector<int>(m , INT_MAX));
        
        queue<vector<int>>q;

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] == 1){
                    minDist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int distance = 1;

        int ans = INT_MIN;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                int row = q.front()[0];
                int col = q.front()[1];
                q.pop();

                for(int i=0;i < 4;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && minDist[nRow][nCol] == INT_MAX){
                        minDist[nRow][nCol] = distance;
                        if(grid[nRow][nCol] == 0) ans = max(ans, minDist[nRow][nCol]);
                        q.push({nRow, nCol});
                    }
                }
            }

            distance++;
        }

        return (ans == INT_MIN || ans == INT_MAX) ? -1 : ans;
    }
};