https://leetcode.com/problems/path-with-minimum-effort/description/

//using dijkstra
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue <pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> > pq;

        pq.push({0, {0, 0}});
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>minEffort(n+1, vector<int>(m+1, 1e9));
        minEffort[0][0] = 0;

        while(!pq.empty()){
            int dif = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n - 1 && col == m - 1) return dif;
            
            int delRow[] = {-1, 0, 1 , 0};
            int delCol[] = {0, 1, 0 , -1};

            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    int newDif = max(abs(heights[nRow][nCol] - heights[row][col]) , dif);
                    if(newDif < minEffort[nRow][nCol]){
                        minEffort[nRow][nCol] = newDif;
                        pq.push({newDif, {nRow, nCol}});
                    }
                }
            }
        }

        return -1;
    }
};