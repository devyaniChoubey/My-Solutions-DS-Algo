https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
    
//because toposort is applicable only for directed acylic graph

Topological Sort applicable for only directed acyclic graph


class Solution {
    public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,stack<int>&s, vector<int>&vis, vector<int> adj[]){
	    vis[node] = 1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it, s, vis, adj);
	        }
	    }
	    s.push(node);
	}


	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V, 0);
	    stack<int>s;
	    for(int i=0;i < V;i++){
	        if(!vis[i]){
	            dfs(i,s, vis, adj);
	        }
	    }
	    
	    vector<int>ans;
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	    
	}
}