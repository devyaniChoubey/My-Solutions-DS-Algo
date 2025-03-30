https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0, 1, 0, -1};
    
            int n = grid.size(), m = grid[0].size();
    
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
            vector<vector<int>>vis(n , vector<int>(m, 0));
    
            vector<pair<int,int>>sortedQueries;
    
            for(int i=0;i < queries.size();i++){
                sortedQueries.push_back({queries[i], i});
            }
    
            sort(sortedQueries.begin() , sortedQueries.end());
    
            vector<int>res(queries.size() , 1);
    
            pq.push({grid[0][0] , 0, 0});
            vis[0][0] = 1;
            int cnt = 0;
            
            for(auto &query:sortedQueries){
                while(!pq.empty()){
                    auto it = pq.top();
                    int val = it[0];
    
                    
                    if(val >= query.first) break;
    
                    cnt++;
                    int row = it[1] , col = it[2];
                    pq.pop();
    
                    
    
                    for(int i=0;i < 4;i++){
                        int nRow = row + delRow[i];
                        int nCol = col + delCol[i];
    
                        if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || vis[nRow][nCol] == 1) continue;
    
                        pq.push({grid[nRow][nCol], nRow, nCol});
                        vis[nRow][nCol] = 1;
                    }
    
                }
    
                res[query.second] = cnt;
            }
    
            return res;
    
    
        }
    };