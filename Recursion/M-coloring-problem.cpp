https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isValid(int node,int col, vector<int>adj[], vector<int>&color){
        for(int adjNode:adj[node]){
            if(color[adjNode] == col) return false;
        }
        
        return true;
    }
    
    bool solve(int node, vector<int>adj[], vector<int>&color,int m,int n){
        if(node >= n){
            return true;
        }
        
        for(int col=1;col <= m;col++){
            if(isValid(node, col, adj, color)){
                color[node] = col;
                
                if(solve(node+1, adj, color, m,n)) return true;
                
                else color[node] = -1;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int>adj[n];
        
        for(int i=0;i < n;i++){
            for(int j=0;j < n;j++){
                if(graph[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int>color(n, -1);
        
        for(int i=0;i < n;i++){
            if(color[i] == -1) {
                if(!solve(i, adj, color, m,n)) return false;
            }
        }
        
        return true;
        
    }
};