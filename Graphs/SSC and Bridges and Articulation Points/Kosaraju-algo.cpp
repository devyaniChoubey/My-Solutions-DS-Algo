https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, stack<int>&st, vector<int>&vis, vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it, st, vis, adj);
	        }
	    }
	    st.push(node);
	}
	
	void dfs2(int node, vector<int>&vis, vector<int>adjT[]){
	    vis[node] = 1;
	    for(auto it:adjT[node]){
            if(!vis[it]){
                dfs2(it, vis, adjT);
            }
        }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V+1, 0);
        stack<int>st;
        
        for(int i=0;i < V;i++){
            if(!vis[i]){
                dfs(i, st, vis, adj);
            }
        }
        
        vector<int>adjT[V];
        
        for(int i=0;i < V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
	             adjT[it].push_back(i);
	        }
        }
        
        int numberOfSCC = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs2(node, vis, adjT);
                numberOfSCC++;
            }
        }
        
        
        return numberOfSCC;
        
        
        
    }
};