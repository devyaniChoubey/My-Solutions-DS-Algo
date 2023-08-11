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
    void dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int delCol[] = {-1, 0, 1, 0};
        int delRow[] = {0, 1, 0, -1};

        grid[i][j] = 2;

        for(int k=0;k < 4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                dfs(nRow, nCol, grid);
            }
        }
    }

    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int found = false;
        queue<pair<int,int>>q;

        int delCol[] = {-1, 0, 1, 0};
        int delRow[] = {0, 1, 0, -1};

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(!found && grid[i][j] == 1){
                    dfs(i, j, grid);
                    found = true;
                }
                if(found && grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            for(int z=0;z < size;z++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
            
                for(int k=0;k < 4;k++){
                    int nRow = row + delRow[k];
                    int nCol = col + delCol[k];

                    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= n) continue;
                    if(grid[nRow][nCol] == 1) continue;
                    if(grid[nRow][nCol] == 2) return level;
                    if(grid[nRow][nCol] == 0){
                        q.push({nRow, nCol});
                        grid[nRow][nCol] = 1;
                    }
                }

            }

            level++;
        }

        return -1;


    }
};