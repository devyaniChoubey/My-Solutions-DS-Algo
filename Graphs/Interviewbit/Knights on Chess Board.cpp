https://www.interviewbit.com/problems/knight-on-chess-board/

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    C--;D--;E--;F--;
    
    int delRow[] = {-1, 1 , -2, -2, -1, 1 , 2, 2};
    int delCol[] = {-2, -2, -1, 1, 2 , 2 , -1, 1};
    
    vector<vector<int>>vis(A+1, vector<int>(B+1, 0));
    
    queue<pair<int, int>>q;
    q.push({C, D});
    vis[C][D] = 1;
    
    int moves = 0;
    while(!q.empty()){
        int size = q.size();
        for(int k=0;k < size;k++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r == E && c == F) return moves;
            
            for(int i=0;i < 8;i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                
                if(nRow < 0 || nRow >= A || nCol < 0 || nCol >= B) continue;
                
                if(!vis[nRow][nCol]){
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                } 
            }
        }
        moves++;
    }
    
    return -1;
}