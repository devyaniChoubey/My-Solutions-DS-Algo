https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();

        vis[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && heights[nRow][nCol] >= heights[row][col]){
                dfs(nRow, nCol, vis, heights);
            }
        }
    }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>pacific(m+1, vector<int>(n+1, 0));
        vector<vector<int>>atlantic(m+1, vector<int>(n+1, 0));

        for(int i=0;i < m;i++){
            if(!pacific[i][0]) dfs(i, 0, pacific, heights);
            if(!atlantic[i][n-1]) dfs(i, n-1, atlantic, heights);
        }

        for(int j=0;j < n;j++){
            if(!pacific[0][j]) dfs(0, j, pacific, heights);
            if(!atlantic[m-1][j]) dfs(m-1, j, atlantic, heights);
        }

        vector<vector<int>>ans;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
               if(pacific[i][j] == 1 && atlantic[i][j] == 1) ans.push_back({i, j}); 
            }
        }

        return ans;

    }
};