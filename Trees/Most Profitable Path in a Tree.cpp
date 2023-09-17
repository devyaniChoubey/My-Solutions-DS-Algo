https://leetcode.com/problems/most-profitable-path-in-a-tree/description/


// 2 DFS

class Solution {
public:
    void dfs(int node, int parent, int dis, vector<int>&dist, vector<int>&par, vector<int>adj[]){
        dist[node] = dis;
        par[node] = parent;

        for(auto it:adj[node]){
            if(it == parent) continue;
            dfs(it, node, dis+1, dist, par, adj);
        }
    }

    int dfs2(int node,vector<int>&amount, vector<int>adj[], int p = 0){
        
        int maxi = INT_MIN;

        for(auto it:adj[node]){
            if(it != p) maxi = max(maxi, dfs2(it, amount, adj, node));
        }

        if(maxi == INT_MIN) return amount[node];
        else return maxi + amount[node];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int>dist(n), par(n);
        vector<int>adj[n];

        for(int i=0;i < edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, 0, 0, dist, par, adj);

        int cur = bob;
        int bob_dist = 0;

        while(cur != 0){
            if(bob_dist < dist[cur]) amount[cur] = 0;
            else if(bob_dist == dist[cur]) amount[cur] /= 2;

            bob_dist++;
            cur = par[cur];
        }

        return dfs2(0, amount, adj);


    }
};


// 1 DFS

class Solution {
public:
    vector<int>distFromBob;
    int bobNode;

    int dfs(int node, int parent, int dis, vector<int>&amount, vector<int>adj[]){
        int curAmount = 0;

        if(node == bobNode) distFromBob[node] = 0;
        else distFromBob[node] = amount.size();

        int maxi = INT_MIN;

        for(auto it:adj[node]){
            if(it == parent) continue; 
            maxi = max(maxi, dfs(it,node,dis+1, amount, adj));
            distFromBob[node] = min(distFromBob[node], distFromBob[it] + 1); 
        }

        if(distFromBob[node] > dis) curAmount = amount[node];
        else if(distFromBob[node] == dis) curAmount = amount[node]/2;

        if(maxi == INT_MIN) return curAmount;
        else return maxi + curAmount;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        bobNode = bob;
        distFromBob.resize(n);
        
        vector<int>adj[n];

        for(int i=0;i < edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, 0, 0, amount, adj);

    }
};