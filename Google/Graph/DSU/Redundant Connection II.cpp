https://leetcode.com/problems/redundant-connection-ii/solutions/108045/c-java-union-find-with-explanation-o-n/

https://leetcode.com/problems/redundant-connection-ii/description/


edges = [[2,1],[3,1],[4,2],[1,4]]

ans = [2,1]


class DisjointSet {
    public:
    vector<int>size, parent;

    DisjointSet(int n){
       size.resize(n+1, 1);
       parent.resize(n+1);

       for(int i=0;i < n;i++) parent[i] = i;
    }

    int findUPar(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
           parent[ulp_v] = ulp_u;
           size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parents(n + 1, 0);
        vector<int> edge1, edge2;
        
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // A node has two parents
            if (parents[v] > 0) {
                // first visted edge
                edge1 = {parents[v], v};
                // current(later) visted edge
                edge2 = {u, v};
                
                // Delete the later edge
                edge[0] = edge[1] = -1;
            }
            parents[v] = u;
        }
        
        DisjointSet ds(n);
        
        // cycle detection
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            // Invalid edge (we deleted in step 1)
            if (u < 0 || v < 0) continue;
            
            int parU = ds.findUPar(u);
            int parV =  ds.findUPar(v);

            // Both u and v are already in the tree
            if (parU == parV) {
                return edge1.empty() ? edge : edge1;
            }

            ds.unionBySize(u, v);
        }
        
        // when no cycle is detected above
        return edge2;

    }
};