https://leetcode.com/problems/graph-valid-tree/description/


For the graph to be a valid tree, it must have exactly n - 1 edges. Any less, 
and it can't possibly be fully connected. Any more, and it has to contain cycles. 
Additionally, if the graph is fully connected and contains exactly n - 1 edges, 
it can't possibly contain a cycle, and therefore must be a tree!


class DisjointSet {
    public:
    vector<int>parent, size;
    DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i <= n;i++) parent[i] = i;
    }


    int findUPar(int node){
        if(node == parent[node]) return node;
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        DisjointSet ds(n);

        for(auto it:edges){
            if(ds.findUPar(it[0]) != ds.findUPar(it[1])) n--;
            else return false;
            ds.unionBySize(it[0] , it[1]);
        }

        return (n == 1);
    }
};