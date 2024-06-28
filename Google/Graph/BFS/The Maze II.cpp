https://leetcode.com/problems/the-maze-ii/description/

class Solution {
public:
    int (vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> minSteps(m, vector<int>(n, INT_MAX));

        queue<vector<int>> q;

        q.push({start[0], start[1], 0});
        minSteps[start[0]][start[1]] = 0;

        int res = INT_MAX;

        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            if(row == destination[0] && col == destination[1]){
                res = min(res, steps);
            }

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = row;
                int nCol = col;
                int minStep = steps;

                while(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && maze[nRow][nCol] == 0){
                    nRow += delRow[i];
                    nCol += delCol[i];
                    minStep++;
                }

                nRow -= delRow[i];
                nCol -= delCol[i];
                minStep--;

                if(minSteps[nRow][nCol] > minStep){
                    minSteps[nRow][nCol] = minStep;
                    q.push({nRow, nCol, minStep});
                }
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};


//Slightly optimised

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> minSteps(m, vector<int>(n, INT_MAX));

        queue<vector<int>> q;

        q.push({start[0], start[1]});
        minSteps[start[0]][start[1]] = 0;

        int res = INT_MAX;

        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i=0;i < 4;i++){
                int nRow = row;
                int nCol = col;
                int minStep = minSteps[row][col];

                while(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && maze[nRow][nCol] == 0){
                    nRow += delRow[i];
                    nCol += delCol[i];
                    minStep++;
                }

                nRow -= delRow[i];
                nCol -= delCol[i];
                minStep--;

                if(minSteps[nRow][nCol] > minStep){
                    minSteps[nRow][nCol] = minStep;
                    if(nRow == destination[0] && nCol == destination[1]){
                        res = min(res, minSteps[nRow][nCol]);
                    }
                    q.push({nRow, nCol, minStep});
                }
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};



