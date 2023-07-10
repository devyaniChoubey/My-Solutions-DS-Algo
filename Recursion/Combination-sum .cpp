https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void solve(int i, vector<int>& candidates,vector<int>&ds, vector<vector<int>>&ans, int target){
         
        if(i >= candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            solve(i, candidates, ds, ans, target-candidates[i]);
            ds.pop_back();
        }
        solve(i+1, candidates, ds, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>ds;
       solve(0,candidates, ds, ans, target);
       return ans;
    }
};