https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
        pair<int, int> destination) {
        // code here
        queue<pair<int,int>>q;
        q.push(source);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m+1, vector<int>(n+1, 1e9));
        dist[source.first][source.second] = 0;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                    if(dist[nRow][nCol] > dist[row][col] + 1){
                        dist[nRow][nCol] = dist[row][col] + 1;
                        q.push({nRow, nCol});
                        if(nRow == destination.first && nCol ==  destination.second){
                            return dist[nRow][nCol];
                        }
                    }
                }
            }
        }
        
        if(dist[destination.first][destination.second] == 1e9) return -1;
        else return dist[destination.first][destination.second];
    }
};