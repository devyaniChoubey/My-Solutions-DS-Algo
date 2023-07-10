https://leetcode.com/problems/combination-sum-ii/

//TLE SOLUTION
void solve(int i,int target,vector<int>& candidates,vector<int>& ds, set<vector<int>>&s){
    int n = candidates.size();
    if(i >= n){
        if(target == 0) s.insert(ds);
        return;
    }
    
    if(candidates[i] <= target){
        ds.push_back(candidates[i]);
        solve(i+1, target - candidates[i], candidates,ds, s);
        ds.pop_back();
    }

    solve(i+1, target, candidates,ds, s);
    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int>ds;
    set<vector<int>>s;
    sort(candidates.begin(), candidates.end());
    solve(0, target, candidates,ds, s);
    vector<vector<int>>ans(s.begin(), s.end());
    return ans;
}


//Optimised

class Solution {
public:
    void solve(int i,int target,vector<int>& candidates,vector<int>& ds, vector<vector<int>>&ans){
        int n = candidates.size();
        if(i > n){
            return;
        }else{
            if(target == 0) ans.push_back(ds);
        }
        
        for(int j=i;j < n;j++){
            if(j > i && candidates[j] == candidates[j-1]) continue;
            
            if(candidates[j] <= target){
                ds.push_back(candidates[j]);
                solve(j+1, target - candidates[j], candidates,ds, ans);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int>ds;
       sort(candidates.begin(), candidates.end());
       vector<vector<int>>ans;
       solve(0, target, candidates,ds, ans);
       return ans;
    }
};