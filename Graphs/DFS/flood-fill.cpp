https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void dfs(int row, int col, int color, vector<vector<int>>& image, int startColor,vector<vector<int>>& vis){
        int delRow[] = { -1, 0, 1, 0};
        int delCol[] = { 0, 1, 0, -1};

        int m = image.size();
        int n = image[0].size();

        vis[row][col] = 1;
        image[row][col] = color;

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0 && image[nRow][nCol] == startColor){
                dfs(nRow, nCol, color, image, startColor, vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
        dfs(sr, sc, color, image, startColor,vis);

        return image;
    }
};