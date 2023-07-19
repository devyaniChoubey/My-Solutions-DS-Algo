https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        int numOfIsland = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        vector<int>ans;
        
        vector<vector<int>> vis(n, vector<int>(m , 0));
        for(auto it:operators){
            if(vis[it[0]][it[1]] == 0){
                vis[it[0]][it[1]] = 1;
                numOfIsland++;
                for(int i=0;i < 4;i++){
                    int nRow = it[0] + delRow[i];
                    int nCol = it[1] + delCol[i];
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 1){
                        int nodeId = m*it[0] + it[1];
                        int adjNodeId = m*nRow + nCol;
                        
                        if(ds.findParent(nodeId) != ds.findParent(adjNodeId)){
                            numOfIsland--;
                            ds.unionBySize(nodeId, adjNodeId);
                        }
                    }
                }
            }
            
            ans.push_back(numOfIsland);
            
        }
        
        return ans;
        
        
    }
};