https://leetcode.com/problems/walls-and-gates/description/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>>q;
        int m = rooms.size();
        int n = rooms[0].size();

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(rooms[i][j] == 0) q.push({i, j});
            }
        }

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

                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && rooms[nRow][nCol] == INT_MAX){
                        rooms[nRow][nCol] = distance;
                        q.push({nRow, nCol});
                    }
                }
            }
            distance++;
        }
    }
};