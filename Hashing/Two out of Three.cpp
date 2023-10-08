https://www.interviewbit.com/problems/two-out-of-three/

vector<int>unique(vector<int>A){
    vector<int>res;
    sort(A.begin() , A.end());
    res.push_back(A[0]);
    for(int i=1;i < A.size();i++){
        if(A[i] != A[i-1]) res.push_back(A[i]);
    }
    return res;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    unordered_map<int, int>count;
    
    A = unique(A);
    B = unique(B);
    C = unique(C);
    
    
    for(int num:A) count[num]++;
    for(int num:B) count[num]++;
    for(int num:C) count[num]++;

    vector<int>result;
    
    for(auto it:count){
        if(it.second >= 2) result.push_back(it.first);
    }
    
    sort(result.begin() , result.end());

    return result;
}

