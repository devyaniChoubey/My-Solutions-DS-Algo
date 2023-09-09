https://leetcode.com/problems/number-of-distinct-islands/description/

class Solution {
public:
    void dfs(int baseRow, int baseCol,int row, int col, vector<vector<int>>& grid,vector<pair<int,int>>&temp){
        int m = grid.size();
        int n = grid[0].size();
        grid[row][col] = 0;

        temp.push_back({row-baseRow, col-baseCol});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                dfs(baseRow,baseCol, nRow,nCol,grid,temp);
            }
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<vector<pair<int,int>>>st;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>>temp;
                    dfs(i, j,i, j, grid,temp);
                    st.insert(temp);
                }
            }
        }

        return st.size();


    }
};


//Method 2

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,string &temp,string dir){
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || col < 0 || row > m-1 || col > n-1 || grid[row][col] == 0) return;

        grid[row][col] = 0;
        temp.append(dir);

        dfs(row-1, col, grid,temp,"u");
        dfs(row+1, col, grid,temp,"d");
        dfs(row, col+1, grid,temp,"r");
        dfs(row, col-1, grid,temp,"l");

        temp.append("b");
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<string>st;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    string temp = "";
                    dfs(i, j, grid,temp, "o");
                    st.insert(temp);
                }
            }
        }

        return st.size();

    }
};