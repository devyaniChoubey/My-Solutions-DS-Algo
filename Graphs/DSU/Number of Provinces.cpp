https://leetcode.com/problems/number-of-provinces/description/

class DisjointSet {
    public:
    vector<int>parent, rank, size;
    DisjointSet(int n){
       parent.resize(n+1);
       rank.resize(n+1,0);
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

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u; 
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<int>adj[V];

        DisjointSet ds(V);

        for(int i=0;i < isConnected.size(); i++){
            for(int j=0;j < isConnected.size(); j++){
                if(i != j && isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }

        vector<int>vis(V, 0);

        int numOfProvinces = 0;
        for(int i=0;i < V;i++){
            if(i == ds.parent[i]) numOfProvinces++;
        }

        return numOfProvinces;
        

    }
};