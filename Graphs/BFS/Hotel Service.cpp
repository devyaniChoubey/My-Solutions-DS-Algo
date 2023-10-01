https://www.interviewbit.com/problems/hotel-service/

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>>dist(n , vector<int>(m, 1e9));
    
    
    queue<pair<int, int>>q;
    
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            if(A[i][j] == 1){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    
    int level = 1;
    while(!q.empty()){
        int size = q.size();
        
        for(int k=0;k < size;k++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || dist[nRow][nCol] != 1e9) continue;
                dist[nRow][nCol] = level;
                q.push({nRow, nCol});
            }
        }
        level++;
    }
    
    vector<int>ans(B.size());
    
    for(int i=0;i < B.size();i++){
        int row = B[i][0] - 1;
        int col = B[i][1] - 1;
        
        ans[i] = dist[row][col];
    }
    
    return ans;
}
