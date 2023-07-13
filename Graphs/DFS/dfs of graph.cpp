https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
    public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsCall(int node, vector<int> adj[],vector<int>&vis, vector<int>&dfs){
        vis[node] = 1;
        dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfsCall(it, adj, vis, dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V+1, 0);
        vector<int>dfs;
        for(int i=0;i < V;i++){
            if(!vis[i]){
                dfsCall(i, adj, vis, dfs);
            }
        }
        return dfs;
    }
}