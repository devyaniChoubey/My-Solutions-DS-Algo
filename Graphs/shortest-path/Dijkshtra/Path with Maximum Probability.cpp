https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue <pair<double, int>> pq;

        vector<double>maxP(n, (double)0.0);

        vector<pair<int, double>>adj[n];

        for(int i=0;i < edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        pq.push({(double)1.0, start_node});
        maxP[start_node] = (double)1.0; 

        while(!pq.empty()){
            int node = pq.top().second;
            int prob = pq.top().first;

            pq.pop();

            for(auto it:adj[node]){
                if(maxP[it.first] < maxP[node]*it.second){
                    maxP[it.first] = maxP[node]*it.second;
                    pq.push({maxP[it.first], it.first});
                }
            }
        }


        return maxP[end_node];

    }
};