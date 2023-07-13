https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int> , int>>q;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 2){
                    q.push({{i, j} , 0});
                }
            }
        }

        int totalTime = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1 , 0};
            int delCol[] = {0, 1, 0, -1};

            for(int j=0;j < 4;j++){
                int nRow = row + delRow[j];
                int nCol = col + delCol[j];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, time+1});
                    totalTime = time+1;
                    grid[nRow][nCol] = 2;
                }
            }
        }


        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }


        return totalTime;
    }
};