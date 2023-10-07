https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &nums, int target) {
    unordered_map<int,int>mp;
    vector<int>result;
    
    int n = nums.size();
    
    for(int i=0;i < n;i++){
        int complement = target - nums[i];
        
        if(mp.find(complement) != mp.end()){
            result.push_back(mp[complement]);
            result.push_back(i+1);
            
            return result;
        }
        
        if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = i + 1;
    }
    
    return result;
}
