https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void solve(int ind, vector<int>&nums, int k, int target, vector<vector<int>>&ans,vector<int>temp){
        if(target == 0 && k == 0){
            ans.push_back(temp);
        }
        if(k == 0 || ind >= nums.size()) return;

        if(k > 0 && target >= nums[ind]){
            temp.push_back(nums[ind]);
            solve(ind+1, nums, k-1, target-nums[ind], ans, temp);
            temp.pop_back();
        }

        solve(ind+1, nums, k, target, ans, temp);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int>nums(9, 0);

        for(int i=0;i < 9;i++) nums[i] = i+1;

        vector<vector<int>>ans;
        vector<int>temp;

        solve(0, nums, k, target, ans, temp);

        return ans;
    }
};