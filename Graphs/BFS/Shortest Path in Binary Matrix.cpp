https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1 && grid[0][0] == 0) return 1;

        int delRow[] = {-1, 0, 1, 0, -1, -1, +1, +1};
        int delCol[] = {0, +1, 0,-1, -1,  +1, -1, +1};

        queue<pair<int, int>>q;

        if(grid[0][0] == 0) {
            q.push({0, 0});
            grid[0][0] = 1;
        }else return -1;

        int steps = 1;

        while(!q.empty()){
            int size = q.size();
            steps++;

            for(int j=0;j < size;j++){
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                for(int i=0;i < 8;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= n) continue;

                    if(grid[nRow][nCol] == 1) continue;

                    if(nRow == n-1 && nCol == n-1 && grid[nRow][nCol] == 0) return steps;
                    
                    if(grid[nRow][nCol] == 0){
                        grid[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }

                }
            }

            
        } 

        return -1;
    }
};