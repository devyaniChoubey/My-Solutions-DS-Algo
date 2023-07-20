https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class DisjointSet {
    public:
    vector<int>size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i <= n;i++) parent[i] = i;
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int n, m;
        for(auto it:stones){
           n = max(n, it[0]);
           m = max(m , it[1]);
        }

        DisjointSet ds(n + m + 2);

        for(auto it:stones){
           ds.unionBySize(it[0], n + 1 + it[1]);
        }

        int noOfComponents = 0;

        for(int i=0;i < n + m + 2;i++){
            int uPar = ds.findUParent(i);
            if(ds.size[uPar] > 1 && i == ds.findUParent(i)) noOfComponents++;
        }

        return stones.size() - noOfComponents;
 
    }
};