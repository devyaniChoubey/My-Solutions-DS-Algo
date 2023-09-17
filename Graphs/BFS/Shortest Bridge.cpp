https://leetcode.com/problems/shortest-bridge/description/

/*
The idea I used in this problem is that. (Note that there is exactly two group of islands).
(1) I will traverse one group of island by DFS and mark this group from number 1 to number 2
    So now the grid has one group of island with number 2 and the other group of island with number 1 and the rest of the grid is number 0.
(2) Now I will do multisource BFS from all the grid[i][j] with value as 1.
(3) Now the final answer will be minimum of all the distances of grid[i][j] with value 2.
(4) So minimum number of flips required is (mn - 1).
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        grid[row][col] = 2;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                dfs(nRow, nCol, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        bool found = false;

        queue<pair<int,int>>q;
        
        for(int i=0;i < n;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1 && !found){
                    dfs(i, j, grid);
                    found = true;
                }

                if(grid[i][j] == 1 && found){
                    q.push({i, j});
                }
                
            }
        }

        int noOfFlips = 0;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                for(int i=0;i < 4;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow < 0 || nRow > n-1 || nCol < 0 || nCol > n-1 || grid[nRow][nCol] == 1) continue;
                    
                    if(grid[nRow][nCol] == 0){
                        q.push({nRow, nCol});
                        grid[nRow][nCol] = 1;
                    }

                    if(grid[nRow][nCol] == 2){
                        return noOfFlips;
                    }
                }
            }

            noOfFlips++;
        }

        return -1;
    }
};