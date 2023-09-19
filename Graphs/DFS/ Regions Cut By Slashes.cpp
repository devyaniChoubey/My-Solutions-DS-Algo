https://leetcode.com/problems/regions-cut-by-slashes/description/

https://leetcode.com/problems/regions-cut-by-slashes/solutions/205674/dfs-on-upscaled-grid/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&graph){
        int n = graph.size();

        graph[row][col] = 1;

        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1 , 0, -1};

        for(int i=0;i < 4;i++){
            int nRow  = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= n || graph[nRow][nCol] == 1) continue;
            
            dfs(nRow, nCol, graph);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>graph(n*3 , vector<int>(n*3, 0));
        
        for(int i=0;i < n;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == '/'){
                    graph[3*i+2][3*j] = graph[3*i+1][3*j+1] = graph[3*i][3*j+2] = 1;
                }else if(grid[i][j] == '\\'){
                    graph[3*i][3*j] = graph[3*i+1][3*j+1] = graph[3*i+2][3*j+2] = 1;
                }
            }
        }

        int regions = 0;

        for(int i=0;i < 3*n;i++){
            for(int j=0;j < 3*n;j++){
                if(graph[i][j] == 0){
                    dfs(i, j, graph);
                    regions++;
                }
            }
        }

        return regions;
    }
};