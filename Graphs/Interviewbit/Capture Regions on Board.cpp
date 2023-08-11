https://www.interviewbit.com/problems/capture-regions-on-board/

void dfs(int row, int col, vector<vector<char> > &A){
    int n = A.size();
    int m = A[0].size();
    
    A[row][col] = 'D';
    
    int delRow[] = {-1, 0, 0 , 1};
    int delCol[] = {0, 1, -1, 0};
    
    for(int k=0;k < 4;k++){
        int nRow = row + delRow[k];
        int nCol = col + delCol[k];
        
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && A[nRow][nCol] == 'O'){
            dfs(nRow, nCol, A);
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(A[i][j] == 'O'){
                    dfs(i, j, A);
                }
            }
        }
    }
    
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            if(A[i][j] == 'O') A[i][j] = 'X';
        }
    }
    
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            if(A[i][j] == 'D') A[i][j] = 'O';
        }
    }
    
}
