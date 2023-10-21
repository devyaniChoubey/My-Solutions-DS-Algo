https://www.interviewbit.com/problems/make-equal-elements-array/

bool check(vector<int> &nums, int x, int y){
    for(auto num:nums){
        if(num - x == y || num + x == y || num == y){}
        else return false;
    }
    
    return true;
}

int Solution::solve(vector<int> &nums, int x) {
    
    if(check(nums, x, nums[0] - x) || check(nums, x, nums[0] + x) || check(nums, x, nums[0])) return true;
    return false;
}
