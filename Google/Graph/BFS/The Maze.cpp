https://leetcode.com/problems/the-maze/description/

https://leetcode.com/problems/the-maze/editorial/


//DFS
class Solution {
public:
    bool dfs(vector<int> cur, vector<int>& destination, vector<vector<int>>& maze,vector<vector<int>>& vis){
        int n = maze.size();
        int m = maze[0].size();

        vis[cur[0]][cur[1]] = 1;

        if(cur[0] == destination[0] && cur[1] == destination[1]) return true;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = cur[0];
            int nCol = cur[1];

            while(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && maze[nRow][nCol] == 0){
                nRow += delRow[i];
                nCol += delCol[i];
            }

            nRow = nRow - delRow[i];
            nCol = nCol - delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && maze[nRow][nCol] == 0 && !vis[nRow][nCol]){
                if(dfs({nRow, nCol} , destination, maze, vis)){
                    return true;
                }
            }
        }

        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        return dfs(start, destination, maze, vis);

    }
};


//BFS


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        queue<pair<int,int>>q;

        q.push({start[0] , start[1]});

        vis[start[0]][start[1]] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == destination[0] && col == destination[1]) return true;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = row;
                int nCol = col;

                while(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && maze[nRow][nCol] == 0){
                    nRow += delRow[i];
                    nCol += delCol[i];
                }

                nRow -= delRow[i];
                nCol -= delCol[i];

                if(!vis[nRow][nCol]){
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }

        }

        return false;

    }
};