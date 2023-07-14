https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
        
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>>dis(m, vector<int>(n, 0));
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            dis[row][col] = dist;

            int delRow[] = {-1, 0, 1 , 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0){
                    q.push({{nRow, nCol} , dist+1});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return dis;
    }
};