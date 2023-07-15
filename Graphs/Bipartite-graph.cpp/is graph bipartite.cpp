//bfs

class Solution {
public:
    bool bfsBipartite(int node, vector<vector<int>>& graph, vector<int>&color){
        int n = graph.size();
        queue<int>q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int ver = q.front();
            q.pop();
            for(auto it:graph[ver]){
                if(color[it] == -1){
                    color[it] = !color[ver];
                    q.push(it);
                }else{
                    if(color[it] == color[ver]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i=0;i < n;i++){
            if(color[i] == -1){
                if(!bfsBipartite(i, graph, color)){
                    return false;
                }
            }
        }

        return true;
        
    }
};


//dfs

class Solution {
public:
    bool dfsBipartite(int node, vector<int>&color, vector<vector<int>>& graph){
        if(color[node] == -1) color[node] = 1;

        for(auto it:graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfsBipartite(it, color, graph) == false){
                    return false;
                }
            }else {
                if(color[it] == color[node])return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i=0;i < n;i++){
            if(color[i] == -1){
                if(dfsBipartite(i, color, graph) == false){
                    return false;
                }
            }
        }

        return true;
        
    }
};
