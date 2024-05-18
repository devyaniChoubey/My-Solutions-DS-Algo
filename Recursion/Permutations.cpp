https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void solve(vector<int>&nums, vector<int>&temp,vector<vector<int>>&ans,int mp[]){
        int n = nums.size();

        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i < n;i++){
            if(!mp[i]){
                temp.push_back(nums[i]);
                mp[i] = 1;
                solve(nums,temp, ans, mp);
                temp.pop_back();
                mp[i] = 0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int mp[n];

        for(int i=0;i < n;i++) mp[i] = 0;

        vector<int>temp;
        solve(nums,temp, ans, mp);
        return ans;
    }
};




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