https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isValid(int col, int node, vector<int>&color, bool graph[101][101]){
        int n = color.size();
        for(int i=0;i < n;i++){
            if(graph[node][i] || graph[i][node]){
                if(color[i] == col) return false;
            }
        }
        
        return true;
    }
    
    bool dfs(int node, int m, vector<int>&color,int n, bool graph[101][101]){
        if(node == n) return true;
        
        for(int col=1;col <= m;col++){
            if(isValid(col, node, color, graph)){
                color[node] = col;
                if(dfs(node+1, m, color, n, graph))return true;
                else color[node] = -1;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int>color(n, -1);
        return dfs(0, m, color, n, graph);
    }
};