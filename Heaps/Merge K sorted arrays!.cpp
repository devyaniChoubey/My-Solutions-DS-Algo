https://www.interviewbit.com/problems/merge-k-sorted-arrays/

vector<int> Solution::solve(vector<vector<int> > &matrix) {
    priority_queue <pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
    
    for(int i=0;i < matrix.size();i++){
        pq.push({matrix[i][0], {i, 0}});
    }
    
    vector<int>res;
    while(!pq.empty()){
        res.push_back(pq.top().first);
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        
        if(col + 1 < matrix[row].size()) pq.push({matrix[row][col+1] , {row, col + 1}});
    }
    
    return res;
    
}
