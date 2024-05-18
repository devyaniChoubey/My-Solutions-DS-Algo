https://leetcode.com/problems/shortest-path-to-get-food/description/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>>q;

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] == '*'){
                    q.push({i, j});
                    grid[i][j] = 'X';
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int distance = 1;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                int row = q.front()[0];
                int col = q.front()[1];
                q.pop();

                for(int i=0;i < 4;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue;
                    if(grid[nRow][nCol] == 'O'){
                        q.push({nRow, nCol});
                        grid[nRow][nCol] = 'X';
                    }else if(grid[nRow][nCol] == '#'){
                       return distance;
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};