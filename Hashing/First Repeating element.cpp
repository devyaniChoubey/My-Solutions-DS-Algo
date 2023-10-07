https://www.interviewbit.com/problems/first-repeating-element/

int Solution::solve(vector<int> &nums) {
    unordered_map<int, int>hash;
    int n = nums.size();
    int minInd = 1e9;
    
    for(int i=0;i < n;i++){
        if(hash[nums[i]] > 0){
            if(hash[nums[i]] < minInd){
                minInd = hash[nums[i]];
            }
        }
        hash[nums[i]] = i + 1;
    }
    
    if(minInd != 1e9) return nums[minInd - 1];
    else return -1;
}
