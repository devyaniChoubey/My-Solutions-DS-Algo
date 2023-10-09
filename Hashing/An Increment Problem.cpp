https://www.interviewbit.com/problems/an-increment-problem/

vector<int> Solution::solve(vector<int> &nums) {
    
    vector<int>res;
    for(int num:nums){
        auto it = find(res.begin() , res.end() , num);
        if(it != res.end()){
            (*it)++;
        }
        res.push_back(num);
    }
    
    return res;

}

https://www.geeksforgeeks.org/modify-given-array-by-incrementing-first-occurrence-of-every-element-by-k/

vector<int> Solution::solve(vector<int> &nums) {
    
    unordered_map<int, set<int>>mp;
    
    for(int i=0;i < nums.size();i++){
        if(mp.find(nums[i]) == mp.end() || mp[nums[i]].size() == 0){
            mp[nums[i]].insert(i);
        }else{
            auto idxx = mp[nums[i]].begin();
            int idx = *idxx;
            mp[nums[i]].erase(idxx);
            nums[idx]++;
            mp[nums[idx]].insert(idx);
            mp[nums[i]].insert(i);
        }
    }
    
    return nums;
}

