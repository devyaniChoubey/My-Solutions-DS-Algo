https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/description/


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {

        //cost, city, discountUsed
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

        vector<vector<int>>adj[n];

        for(auto &it:highways){
            int u = it[0] , v = it[1], toll = it[2];
            adj[u].push_back({v, toll});
            adj[v].push_back({u, toll});
        }

        pq.push({0, 0, 0});
        vector<vector<int>>dist(n, vector<int>(discounts+1, 1e9));
        dist[0][0] = 0;

        while(!pq.empty()){
            int cost = pq.top()[0];
            int node = pq.top()[1];
            int discountUsed = pq.top()[2];
            pq.pop();

            if(cost > dist[node][discountUsed]) {continue;}

            

            for(auto &it:adj[node]){
                int adjNode = it[0] , toll = it[1];

                if(dist[adjNode][discountUsed] > cost + toll){
                    dist[adjNode][discountUsed] = cost+toll;
                    pq.push({dist[adjNode][discountUsed], adjNode, discountUsed});
                }

                if(discountUsed < discounts){
                    if(dist[adjNode][discountUsed+1] > cost + (toll/2)){
                        dist[adjNode][discountUsed+1] = cost + (toll/2);
                        pq.push({dist[adjNode][discountUsed+1], adjNode, discountUsed+1});
                    }
                }
            }
        }

        int minCost = 1e9;

        for(int i=0;i <= discounts;i++){
            if(dist[n-1][i] != 1e9) minCost = min(minCost, dist[n-1][i]);
        }

        if(minCost == 1e9) return -1;
        else return minCost;
    }
};