https://www.interviewbit.com/problems/pair-with-given-difference/

int Solution::solve(vector<int> &A, int B) {
    
    unordered_set<int>seen;
    
    for(auto num:A){
        int target1 = num - B;
        int target2 = num + B;
        
        if(seen.count(target1) || seen.count(target2)) return 1;
        
        seen.insert(num);
    }
    return 0;
    
    
}