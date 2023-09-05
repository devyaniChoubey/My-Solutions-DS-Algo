https://leetcode.com/problems/detonate-the-maximum-bombs/description/

https://leetcode.com/problems/detonate-the-maximum-bombs/editorial/

class Solution {
public:
    void dfs(int node, vector<int>graph[], vector<int>&vis, int &cnt){
        vis[node] = 1;
        cnt++;

        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it, graph, vis, cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int>graph[n];

        for(int i=0;i < n;i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for(int j=0;j < n;j++){
                if(i == j) continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long r2 = bombs[j][2];

                if((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <= r1*r1){
                    graph[i].push_back(j);
                }
            }
        }
        
        int maxBombs = INT_MIN;
        

        for(int i=0;i < n;i++){
            vector<int>vis(n, 0);
            int bombsCnt = 0;
            dfs(i, graph, vis, bombsCnt);
            maxBombs = max(bombsCnt, maxBombs);
        }

        return maxBombs;


    }
};