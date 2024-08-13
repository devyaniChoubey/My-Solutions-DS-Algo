https://leetcode.com/problems/magic-squares-in-grid/


class Solution {
public:
    bool isMagicGrid(int row,int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(row+3 > m || col+3 > n) return false;

        vector<int>seen(10, 0);

        for(int k=row;k < row+3;k++){
            for(int l=col;l < col+3;l++){
                if(grid[k][l] > 9 || grid[k][l] < 1 || seen[grid[k][l]]) return false;
                seen[grid[k][l]] = 1;
            }
        }

        int rowSum = 0;

        for(int k=row;k < row+3;k++){
            int curSum = grid[k][col] + grid[k][col+1] + grid[k][col+2];
            if(k > row && curSum != rowSum) return false;
            rowSum = curSum;
        }

        for(int l=col;l < col+3;l++){
            int curSum = grid[row][l] + grid[row+1][l] + grid[row+2][l];
            if(curSum != rowSum) return false;
        }

        int diagSum = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];

        int antidiagSum = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];

        if(rowSum != diagSum || antidiagSum != rowSum) return false;

        return true;
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int magicGridCnt = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(isMagicGrid(i, j, grid)) magicGridCnt++;
            }
        }

        return magicGridCnt;
    }
};