https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int countPaths(long long n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(int i=0;i < roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        long long mod = (1000000000 + 7);

        vector<long long>ways(n, 0);
        vector<long long>dist(n, LONG_MAX);

        dist[0] = 0;
        ways[0] = 1;

        //{dist , node}
        priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
        
        pq.push({0, 0});

        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                long long adjNode = it.first;
                long long edgeWt = it.second;

                if(dist[adjNode] > dis + edgeWt){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }else if(dist[adjNode] == dis + edgeWt){
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }

        return (ways[n-1])%mod;


    }
};