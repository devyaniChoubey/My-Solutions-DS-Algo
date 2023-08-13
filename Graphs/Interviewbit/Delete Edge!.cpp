https://www.interviewbit.com/problems/delete-edge/


int dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& A,long long totalSum, long long &maxProduct) {
    vis[node] = 1;

    int curSum = A[node - 1]; // Corrected index

    for (auto it : adj[node]) {
        if (!vis[it]) {
            curSum += dfs(it, adj, vis, A,totalSum, maxProduct);
        }
    }

    maxProduct = max(maxProduct, (totalSum - curSum) * curSum);

    return curSum;
}

int Solution::deleteEdge(vector<int>& A, vector<vector<int>>& B) {
    int V = A.size();
    vector<int> vis(V + 1, 0);

    long long totalSum = 0; // Reset totalSum for each test case
    for (auto it : A) {
        totalSum += it;
    }
    
    long long maxProduct = -1e9;

    vector<int> adj[V + 1];

    for (auto it : B) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    dfs(1, adj, vis, A,totalSum, maxProduct); // Start DFS from node 1
    
    long long MOD = 1e9+7;

    return maxProduct % MOD; // Apply modular arithmetic
}