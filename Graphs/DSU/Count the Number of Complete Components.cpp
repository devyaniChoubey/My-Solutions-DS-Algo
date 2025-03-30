

https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2025-03-22

class DisjointSet {
    public:
        vector<int> par, size;
    
        DisjointSet(int n) {
            par.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }
    
        int findUPar(int node) {
            if (par[node] == node) return node;
            return par[node] = findUPar(par[node]);
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
    
            if (ulp_u == ulp_v) return;
    
            if (size[ulp_u] < size[ulp_v]) {
                par[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                par[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            DisjointSet ds(n);
            unordered_map<int, int> edgeCnt;
    
            for (auto& it : edges) {
                int u = it[0], v = it[1];
                ds.unionBySize(u, v);
            }
    
            for (auto& it : edges) {
                int u = it[0], v = it[1];
                int ulp_u = ds.findUPar(u);
                edgeCnt[ulp_u]++;
            }
    
            
    
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (ds.findUPar(i) == i) {
                    int size = ds.size[i];
                    int totalEdges = (size * (size - 1)) / 2;
                    if (edgeCnt[i] == totalEdges) {
                        cnt++;
                    }
                }
            }
    
            return cnt;
        }
    };