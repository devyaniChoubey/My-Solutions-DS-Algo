https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

//Method 1
class Solution {
public:
    std::vector<std::vector<std::vector<int>>> dir= {
        {{0, -1} , {0, 1}},
        {{-1, 0} , {1, 0}},
        {{0, -1} , {1, 0}},
        {{0, 1} , {1, 0}},
        {{-1, 0} , {0, -1}},
        {{-1, 0} , {0, 1}}
    };

    bool dfs(int r, int c, vector<vector<int>>& grid,vector<vector<int>>&vis){
        int m = grid.size();
        int n = grid[0].size();

        if(r == m-1 && c == n-1) return true; // Reach bottom-right cell -> Valid path

        vis[r][c] = 1;

        int streetType = grid[r][c];

        for(int nextDir=0;nextDir < 2;nextDir++){
            int nRow = r + dir[streetType - 1][nextDir][0];
            int nCol = c + dir[streetType - 1][nextDir][1];

            if(nRow < 0 || nCol < 0 || nRow >= m || nCol >= n || vis[nRow][nCol]) continue;

            int newStreetType = grid[nRow][nCol];

            for(int backDir=0;backDir < 2;backDir++){ // Check next cell can go back to current cell
                if(nRow + dir[newStreetType - 1][backDir][0] == r && nCol + dir[newStreetType - 1][backDir][1] == c){
                    if(dfs(nRow, nCol, grid, vis)) return true;
                }
            }
        }

        return false;
       
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
        return dfs(0, 0,grid,vis);
    };
};



//Method 2

class Solution {
public:
    vector<vector<vector<int>>>dir = {
        {{0, -1} , {0, 1}},
        {{-1, 0} , {1, 0}},
        {{0, -1} , {1, 0}},
        {{0, 1} , {1, 0}},
        {{-1, 0} , {0, -1}},
        {{-1, 0} , {0, 1}}
    };

    bool dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(r == m-1 && c == n-1) return true; // Reach bottom-right cell -> Valid path
        vis[r][c] = 1;

        int streetType = grid[r][c];

        for(auto nextDir:dir[streetType-1]){
            int nRow = r + nextDir[0];
            int nCol = c + nextDir[1];

            if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n || vis[nRow][nCol]) continue;

            int newStreetType = grid[nRow][nCol];

            for(auto backDir:dir[newStreetType - 1]){ // Check next cell can go back to current cell
                if(nRow + backDir[0] == r && nCol + backDir[1] == c){
                    if(dfs(nRow, nCol, vis, grid)) return true;
                }
            }
        }

        return false;
    }

    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));

        return dfs(0, 0, vis, grid);

    };
};