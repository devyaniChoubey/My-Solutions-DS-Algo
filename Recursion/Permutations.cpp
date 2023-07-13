https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void solve(int ind,vector<int>& nums, vector<vector<int>>&ans){
        if(ind >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=ind;j < nums.size();j++){
            swap(nums[ind], nums[j]);
            solve(ind+1, nums,ans);
            swap(nums[j],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0, nums,ans);
        return ans;
    }
};