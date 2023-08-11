https://www.interviewbit.com/problems/path-in-matrix/

int Solution::checkPath(vector<vector<int> > &A) {
    int n = A.size();
    queue<pair<int, int>>q;
    for(int i=0;i < n;i++){
        for(int j=0;j < n; j++){
            if(A[i][j] == 1) {
                q.push({i , j});
                A[i][j] = 0;
            }
        }
    }
    
    int delRow[] = { -1, 0 , 1, 0 };
    int delCol[] = { 0, +1, 0, -1 };
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        for(int i=0;i < 4;i++){
            int nRow = it.first + delRow[i];
            int nCol = it.second + delCol[i];
            
            if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= n) continue;
            if(A[nRow][nCol] == 0) continue;
            if(A[nRow][nCol] == 2) return 1;
            if(A[nRow][nCol] == 3){
                A[nRow][nCol] = 0;
                q.push({nRow, nCol});
            } 
                
        }
       
    }
    
    return 0;
}
