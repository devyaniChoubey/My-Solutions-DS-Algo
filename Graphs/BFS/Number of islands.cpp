https://leetcode.com/problems/number-of-islands/description/                                        

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numIslands = 0;
        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    //bfs start
                    queue<pair<int,int>>q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    numIslands++;
                    while(!q.empty()){
                        int curRow = q.front().first;
                        int curCol = q.front().second;
                        q.pop();
                        int delRow[] = {-1, 0, 1, 0};
                        int delCol[] = {0, 1, 0, -1};
                        for(int i=0;i < 4;i++){
                            int newRow = curRow + delRow[i];
                            int newCol = curCol + delCol[i];
                            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && vis[newRow][newCol] == 0 && grid[newRow][newCol] == '1'){
                                vis[newRow][newCol] = 1;
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }

        return numIslands;
    }
};