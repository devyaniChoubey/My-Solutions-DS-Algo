https://leetcode.com/problems/tree-diameter/

class Solution {
public:
    int ans = 0;
    int solve(int root, vector<int>adj[],vector<int>&vis){
        int l1 = 0, l2 = 0;
        vis[root] = 1;

        for(int adjNode:adj[root]){
            if(vis[adjNode]) continue;
            int len = solve(adjNode, adj,vis);
            if(len > l1){
                l2 = l1;
                l1 = len;
            }else if(len > l2){
                l2 = len;
            }
        }

        ans = max(ans, l1 + l2);
        return 1 + max(l1, l2);
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adj[n+1];
        vector<int>vis(n+1, 0);

        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        solve(0, adj, vis);
        return ans;

    }
};