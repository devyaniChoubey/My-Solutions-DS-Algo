https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

class Solution {
    public:
    void dfs(int row, int col, int startRow, int startCol, vector<vector<int>>& grid,
    vector<pair<int,int>>&v){
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = 0;
        v.push_back({row - startRow, col - startCol});
        
        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == 1){
                dfs(nRow, nCol, startRow, startCol, grid, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>>s;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>>v;
                    dfs(i, j , i, j, grid, v);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
}