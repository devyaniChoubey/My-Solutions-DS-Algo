https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

class Solution {
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   vector<int>inDegree(V, 0);
	   vector<int>topo;
	   
	   for(int ver=0;ver < V;ver++){
	       for(auto it: adj[ver]){
	           inDegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int ver=0;ver < V;ver++){
	      if(inDegree[ver] == 0) q.push(ver);
	   }
	   
	   while(!q.empty()){
	       int node = q.front();
	       topo.push_back(node);
	       q.pop();
	       for(auto it:adj[node]){
	           inDegree[it]--;
	           if(inDegree[it] == 0) q.push(it);
	       }
	   }
	   
	   return topo;
	    
	}
}