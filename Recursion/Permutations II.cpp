https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, unordered_map<int,int>&mp,vector<vector<int>>&ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i < nums.size();i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            if(mp[nums[i]] > 0){
                curr.push_back(nums[i]);
                mp[nums[i]]--;
                solve(nums, curr, mp, ans);
                mp[nums[i]]++;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin() , nums.end());
        vector<int>curr;

        for(int &num:nums) mp[num]++;

        vector<vector<int>>ans;

        solve(nums, curr, mp, ans);

        return ans;
    }
};