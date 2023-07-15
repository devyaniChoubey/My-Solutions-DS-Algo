
//if size of toposort is equal to no of vertex in graph then there is no cycle
//because toposort is applicable only for directed acylic graph

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>inDegree(V, 0);
        for(int ver=0;ver < V;ver++){
            for(auto it:adj[ver]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        
        for(int ver=0;ver < V;ver++){
            if(inDegree[ver] == 0) q.push(ver);
        }
        
        int verCnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            verCnt++;
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
        }
        
        if(verCnt == V) return false;
        else return true;
    }


