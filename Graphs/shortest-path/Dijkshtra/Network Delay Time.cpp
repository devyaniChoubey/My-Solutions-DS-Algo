https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //{dist, node}
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int>dist(n+1, 1e9);
        
        vector<pair<int, int>>adj[n+1];

        dist[k] = 0;
        pq.push({0, k});

        for(int i=0;i < times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        int ans = -1e9;

        for(int i=1;i <= n;i++){
            ans = max(ans, dist[i]);
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};




class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //{dist, node}
        vector<int>dist(n+1, 1e9);

        set<pair<int,int>>st;
        
        vector<pair<int, int>>adj[n+1];

        dist[k] = 0;
        st.insert({0, k});

        for(int i=0;i < times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        while(!st.empty()){
            int node = st.begin()->second;
            st.erase(st.begin());

            for(auto it:adj[node]){
                if(dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                    st.insert({dist[it.first], it.first});
                }
            }
        }

        int ans = -1e9;

        for(int i=1;i <= n;i++){
            ans = max(ans, dist[i]);
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};