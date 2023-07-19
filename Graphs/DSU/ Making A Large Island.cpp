https://leetcode.com/problems/making-a-large-island/description/

class DisjointSet {
    
    public:
    vector<int>parent, rank, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int countOfOne = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < n;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    countOfOne++;
                    int nodeId = n*i+j;
                    for(int k=0;k < 4;k++){
                        int nRow = i + delRow[k];
                        int nCol = j + delCol[k];

                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                            int adjNodeId = nRow*n + nCol;
                            ds.unionBySize(nodeId, adjNodeId);
                        }
                    }
                }
            }
        }

        int largestIslandSize = 0;
        for(int i=0;i < n;i++){
            for(int j=0;j < n;j++){
                int sizeOfIsland = 1;
                if(grid[i][j] == 0){
                    set<int>st;
                    int nodeId = n*i+j;
                    for(int k=0;k < 4;k++){
                        int nRow = i + delRow[k];
                        int nCol = j + delCol[k];

                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                            int adjNodeId = nRow*n + nCol;
                            int uPar = ds.findParent(adjNodeId);
                            if(st.find(uPar) == st.end()){
                                sizeOfIsland += ds.size[uPar];
                                st.insert(uPar);
                            }
                        }
                    }
                }
                largestIslandSize = max(largestIslandSize, sizeOfIsland);
            }
        }

        if(countOfOne == n*n) return n*n;
        else return largestIslandSize;


    }
};