void solve(int ind, vector<int>&temp,  vector<vector<int>>&ans, vector<int> &nums,int target){
    if(ind == nums.size() && target == 0){
        ans.push_back(temp);
        return;
    }

    if(ind == nums.size()){
        return;
    }
    
    if(target >= nums[ind]){
        temp.push_back(nums[ind]);
        solve(ind+1, temp, ans,nums, target - nums[ind]);
        temp.pop_back();
    }
    
    solve(ind+1, temp, ans,nums, target);
}

vector<vector<int>> subarraysWithSumK(vector<int> nums, long long target) {
    // Write your code here

    vector<vector<int>>ans;
    vector<int>temp;
    solve(0, temp, ans,nums, target);
    return ans;
}


//Return only one subarray with sum k

bool solve(int ind, vector<int>&temp,  vector<vector<int>>&ans, vector<int> &nums,int target){
    if(ind == nums.size() && target == 0){
      ans.push_back(temp);
      return true;
    }

    if(ind == nums.size()){
      return false;
    }
    
    if(target >= nums[ind]){
      temp.push_back(nums[ind]);
      if(solve(ind+1, temp, ans,nums, target - nums[ind])) return true;
      temp.pop_back();
    }
    
    if(solve(ind+1, temp, ans,nums, target)) return true;

    return false;
}

vector<vector<int>> subarraysWithSumK(vector<int> nums, long long target) {
    // Write your code here

    vector<vector<int>>ans;
    vector<int>temp;
    solve(0, temp, ans,nums, target);
    return ans;
}