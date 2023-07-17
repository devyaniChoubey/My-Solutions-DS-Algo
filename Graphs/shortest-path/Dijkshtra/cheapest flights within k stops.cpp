https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int,int>>>q;
        q.push({0, {0, src}});
        vector<int>dist(n, 1e9);
        dist[src] = 0;

        vector<pair<int,int>>adj[n];

        for(int i=0;i < flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        while(!q.empty()){
            int stops = q.front().first;
            int dis = q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if(stops > k) break;
            
            for(auto it:adj[node]){
                if(dist[it.first] > dis + it.second){
                    dist[it.first] = dis + it.second;
                    q.push({stops + 1, {dist[it.first], it.first}});
                }
            }

        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};