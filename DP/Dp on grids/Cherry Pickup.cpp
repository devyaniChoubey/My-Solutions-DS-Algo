https://leetcode.com/problems/cherry-pickup/

/*
DP Solution O(n^4) memory:
Instead of sending a person down and then reversing it's direction to up. 
What we are doing here is we are hypothetically sending 2 person down.
So if they land on same cherry grid[i][j] we will add only one cherry, 
and if they land on 2 different grids we will add two cherries corresponding to the grids.
Since there are 2 person thus total 4 moves are possible:
Person1->Right && Person2->Right
Person1->Right && Person2->Down
Person1->Down && Person2->Right
Person1->Down && Person2->Down
*/ 


//Recursive
class Solution {
public:
    int pickCherries(int i1, int j1,int i2, int j2, vector<vector<int>>& grid){
        int n = grid.size();
        if(i1 > n-1 || i2 > n-1 || j1 > n-1 || j2 > n-1) return -1e8;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;

        // here i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1 (since they have moved same number of steps)
        if(i1 == n-1 && i2 == n-1 && j1 == n-1 && j2 == n-1) return grid[n-1][n-1];
        
        int cherries = 0;
        if(i1 == i2 && j1 == j2) cherries = grid[i1][j1];
        else cherries = grid[i1][j1] + grid[i2][j2];

        int maxi = -1e8;
        maxi = max(maxi, pickCherries(i1+1, j1, i2, j2+1, grid));
        maxi = max(maxi, pickCherries(i1+1, j1, i2+1, j2, grid));
        maxi = max(maxi, pickCherries(i1, j1+1, i2+1, j2, grid));
        maxi = max(maxi, pickCherries(i1, j1+1, i2, j2+1, grid));

        maxi += cherries;

        return maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        return max(0, pickCherries(0, 0, 0, 0, grid));
    }
};



//Memoised
class Solution {
public:
    int dp[51][51][51][51];
    int pickCherries(int i1, int j1,int i2, int j2, vector<vector<int>>& grid){
        int n = grid.size();
        if(i1 > n-1 || i2 > n-1 || j1 > n-1 || j2 > n-1) return -1e8;
        if(i1 == n-1 && i2 == n-1 && j1 == n-1 && j2 == n-1) return grid[n-1][n-1];
        
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;

        if(dp[i1][i2][j1][j2] != -1) return dp[i1][i2][j1][j2];
        int cherries = 0;
        if(i1 == i2 && j1 == j2) cherries = grid[i1][j1];
        else cherries = grid[i1][j1] + grid[i2][j2];

        int maxi = -1e8;
        maxi = max(maxi, pickCherries(i1+1, j1, i2, j2+1, grid));
        maxi = max(maxi, pickCherries(i1, j1+1, i2+1, j2, grid));
        maxi = max(maxi, pickCherries(i1+1, j1, i2+1, j2, grid));
        maxi = max(maxi, pickCherries(i1, j1+1, i2, j2+1, grid));

        maxi += cherries;

        return dp[i1][i2][j1][j2] = maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof dp);
        return max(0, pickCherries(0, 0, 0, 0, grid));
    }
};