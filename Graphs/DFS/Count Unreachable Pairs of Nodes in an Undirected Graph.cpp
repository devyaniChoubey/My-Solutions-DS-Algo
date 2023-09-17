https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution {
public:
    void dfs(int node, int &size, vector<int>&vis, vector<int>adj[]){
        size++;
        vis[node] = 1;

        for(auto it:adj[node]){
            if(!vis[it]) dfs(it, size, vis, adj);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>sizes;
        vector<int>adj[n];

        for(int i=0;i < edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>vis(n, 0);

        for(int i=0;i < n;i++){
            if(!vis[i]){
                int size = 0;
                dfs(i, size, vis, adj);
                sizes.push_back(size);
            }
        }

        long long ans = 0;

        for(auto it:sizes){
            ans += (long long)(it)*(long long)(n - it);
        }

        return ans/2;

    }
};