https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<vector<int>>q;

        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';


        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int distance = 1;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                int row = q.front()[0];
                int col = q.front()[1];
                q.pop();

                for(int i=0;i < 4;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue;

                    if(maze[nRow][nCol] == '.' && (nRow == 0 || nCol == 0 || nRow == n - 1 || nCol == m - 1)){
                       return distance;
                    }else if(maze[nRow][nCol] == '.'){
                        q.push({nRow, nCol});
                        maze[nRow][nCol] = '+';
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};