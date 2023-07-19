https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //{wt, node, parent}
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<int>vis(V, 0);
        pq.push({0, {0, -1}});
        
        //store mst sum
        int ans = 0;
        
        vector<pair<int,int>>mst;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            
            if(par != -1 && vis[node] == 0) {
                //store mst edges
                mst.push_back({node, par});
            }
            
            if(vis[node] == 0){
                ans += wt;
                vis[node] = 1;
                for(auto it:adj[node]){
                    if(!vis[it[0]]){
                        pq.push({it[1] , {it[0] , node}});
                    }
                }
            }
            
        }
        
        return ans;
        
    }

};