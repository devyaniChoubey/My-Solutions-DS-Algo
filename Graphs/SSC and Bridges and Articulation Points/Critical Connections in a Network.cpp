https://leetcode.com/problems/critical-connections-in-a-network/description/

time[] -> store the time of insertion during dfs

low[] -> minimum of all adjacent nodes apart from parent node

class Solution {
public:
    int timer = 1;
    void dfs(int node, int par, vector<int>&vis, vector<int>adj[], int time[] , int low[], vector<vector<int>>&bridges){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;

        for(auto it:adj[node]){
            if(it == par) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, time, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > time[node]){
                    bridges.push_back({it, node});
                }
            } else if(vis[it] == 1){
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n, 0);
        int time[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0, -1, vis, adj, time, low, bridges);
        return bridges;
    }
};