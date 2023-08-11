https://www.interviewbit.com/problems/min-cost-path/


int Solution::solve(int A, int B, vector<string> &C) {
    priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    //cost, row , col
    pq.push({0, {0, 0}});
    
    
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1 , 0, -1};
    string s="URDL";
    
    vector<vector<int>>dist(A+1, vector<int>(B+1, 1e9));
    dist[0][0] = 0; 
    
    while(!pq.empty()){
        auto it = pq.top();
        int cost = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();
        
        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow < 0 || nRow >= A || nCol < 0 || nCol >= B) continue;
            cost = dist[row][col];
            if(s[i] != C[row][col]) cost++;
            
            if(dist[nRow][nCol] > cost){
                pq.push({cost, {nRow, nCol}});
                dist[nRow][nCol] = cost;
            }
        }
        
        
    }
    
    return dist[A-1][B-1];
}
