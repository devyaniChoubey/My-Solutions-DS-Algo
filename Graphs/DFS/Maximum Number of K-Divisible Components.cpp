https://leetcode.com/problems/maximum-number-of-k-divisible-components/

class Solution {
public:
    int ans = 0;

    long long solve(int root, vector<int>adj[] , vector<int>& values, int k, int n,vector<int>&vis){
        long long sum = values[root];
        vis[root] = 1;

        for(int adjNode:adj[root]){
            if(!vis[adjNode])sum += solve(adjNode, adj, values, k, n,vis);
        }

        if(sum % k == 0) {
            ans++;
            return 0;
        }else {
            return sum;
        }

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        vector<int>vis(n, 0);

        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        solve(0, adj, values, k, n,vis);

        return ans;
    }
};