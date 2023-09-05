https://leetcode.com/problems/path-with-maximum-minimum-value/

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        priority_queue<pair<int ,pair<int,int>>>pq;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>maxPath(m, vector<int>(n, -1e9));

        pq.push({grid[0][0] , {0, 0}});

        maxPath[0][0] = grid[0][0];

        while(!pq.empty()){
            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, -1, 0, 1};

            if(row == m-1 && col == n-1) return val;

            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow < 0 || nRow > m-1 || nCol < 0 || nCol > n-1) continue;

                int newVal = min(val, grid[nRow][nCol]);

                if(newVal > maxPath[nRow][nCol]){
                    pq.push({newVal,{ nRow, nCol}});
                    maxPath[nRow][nCol] = newVal;
                }
            }
        }

        return -1;
    }
};