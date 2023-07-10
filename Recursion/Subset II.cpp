https://leetcode.com/problems/subsets-ii/description/

class Solution {
    void solve(int i, vector<int>&ds, set<vector<int>>&s, vector<int>& nums){
        int n = nums.size();
        if(i >= n){
            s.insert(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        solve(i+1, ds, s, nums);
        ds.pop_back();
        solve(i+1, ds, s , nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        vector<int>ds;
        solve(0, ds, s, nums);
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
}



//Optimised
class Solution {
public:
    void solve(int i, vector<int>&ds, vector<vector<int>>&ans, vector<int>& nums){
        int n = nums.size();
        if(i > n) return;
        else{
            ans.push_back(ds);
        }

        for(int j=i;j < n;j++){
            if(j > i && nums[j] == nums[j-1])continue;
            ds.push_back(nums[j]);
            solve(j+1, ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>>ans;
      vector<int>ds;
      solve(0, ds, ans, nums);
      return ans;
    }
};