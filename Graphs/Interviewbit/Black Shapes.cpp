https://www.interviewbit.com/problems/black-shapes/

void dfs(int r, int c, vector<string> &A){
    int n = A.size();
    int m = A[0].size();
    A[r][c] = 'O';
    
    int delRow[] = {-1, 0, 1 , 0};
    int delCol[] = {0, 1, 0, -1};
    
    for(int i=0;i < 4;i++){
        int nRow = r + delRow[i];
        int nCol = c + delCol[i];
        
        if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue;
        if(A[nRow][nCol] == 'X'){
            dfs(nRow, nCol, A);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    int blackShapes = 0;
    
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            if(A[i][j] == 'X'){
                blackShapes++;
                dfs(i, j, A);
            }
        }
    }
    
    return blackShapes;
}
