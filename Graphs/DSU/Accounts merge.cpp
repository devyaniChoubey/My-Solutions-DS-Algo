https://leetcode.com/problems/accounts-merge/description/


class DisjointSet {
    vector<int>parent, rank, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i < n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
       if(parent[node] == node)return node;
       return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u , int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void unionByRank(int u , int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int>accountIndex;
        int n = accounts.size();
        DisjointSet ds(n);

        for(int i=0;i < n;i++){
            for(int j=1;j < accounts[i].size();j++){
                if(accountIndex.find(accounts[i][j]) == accountIndex.end()) accountIndex[accounts[i][j]] = i;
                else{
                   ds.unionBySize(accountIndex[accounts[i][j]], i);
                }
            }
        }

        vector<string>mergedMail[n];

        for(auto it:accountIndex){
            int par = ds.findParent(it.second);
            mergedMail[par].push_back(it.first);
        }

        vector<vector<string>>ans;

        for(int i=0;i < n;i++){
            if(mergedMail[i].size() != 0){
                vector<string>temp;
                sort(mergedMail[i].begin(), mergedMail[i].end());
                temp.push_back(accounts[i][0]);
                for(int j=0;j < mergedMail[i].size();j++) temp.push_back(mergedMail[i][j]);
                ans.push_back(temp);
            }
            
        }

        return ans;
    }
};