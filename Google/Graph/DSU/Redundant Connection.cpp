

https://leetcode.com/problems/redundant-connection/description/


class DisjointSet {
    public:
    vector<int>size, parent;

    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);

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

        if(size[ulp_v] > size[ulp_v]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>ans;
        DisjointSet ds(n+1);
        for(int i=0;i < n;i++){
            int u = edges[i][0] , v = edges[i][1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                ans = {u, v};
            }
            ds.unionBySize(u, v);
        }

        return ans;
    }
};