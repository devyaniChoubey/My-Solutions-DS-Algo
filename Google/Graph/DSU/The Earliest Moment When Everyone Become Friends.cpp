https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/

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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DisjointSet ds(n);
        int ans = -1;

        sort(logs.begin() , logs.end());

        for(int i=0;i < logs.size();i++){
            if(ds.findUPar(logs[i][1]) != ds.findUPar(logs[i][2])){
                ans = logs[i][0];
                n--;
            }
            ds.unionBySize(logs[i][1] , logs[i][2]);
        }

        if(n == 1)return ans;
        return -1;
    }
};