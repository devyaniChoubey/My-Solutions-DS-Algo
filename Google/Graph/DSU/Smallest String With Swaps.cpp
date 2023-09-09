https://leetcode.com/problems/smallest-string-with-swaps/description/

https://leetcode.com/problems/smallest-string-with-swaps/solutions/388257/c-with-picture-union-find/

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DisjointSet ds(n);

        for(auto it:pairs){
            ds.unionBySize(it[0], it[1]);
        }

        vector<vector<int>>mp(n);

        for(int i=0;i < n;i++){
            mp[ds.findUPar(i)].push_back(i);
        }

        for(int i=0;i < n;i++){
            string sb = "";
            for(int j=0;j < mp[i].size();j++){
                sb += s[mp[i][j]];
            }
            sort(sb.begin(), sb.end());

            for(int j=0;j < mp[i].size();j++){
                s[mp[i][j]] = sb[j];
            }
        }

        return s;
    }
};