
https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    
    void solve(int row, int col, string path, vector<string>&ans,vector<vector<int>> &grid){
        
        int n = grid.size();
        
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        grid[row][col] = 2;
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0, 1, 0,-1};
        
        for(int k=0;k < 4;k++){
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];
            
            if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= n || grid[nRow][nCol] != 1) continue;
            
            if(k == 0)  solve(nRow, nCol, path + "U", ans, grid);
            if(k == 1)  solve(nRow, nCol, path + "R", ans, grid);
            if(k == 2)  solve(nRow, nCol, path + "D", ans, grid);
            if(k == 3)  solve(nRow, nCol, path + "L", ans, grid);
            
            grid[nRow][nCol] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        if(grid[0][0] == 0 || grid[n-1][n-1] == 0) return {"-1"};
        vector<string>ans;
        
        solve(0, 0, "", ans, grid);
        
        return ans;
    }
};