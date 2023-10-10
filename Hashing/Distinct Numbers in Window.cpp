https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &nums, int B) {
    vector<int>result;
    
    if(B > nums.size()) return result;

    unordered_map<int, int> frequency;
    
    for(int i=0;i < nums.size();i++){
        frequency[nums[i]]++;
        if(i - B + 1 >= 0){
            result.push_back(frequency.size());
            frequency[nums[i-B+1]]--;
            if(frequency[nums[i-B+1]] == 0) frequency.erase(nums[i-B+1]);
        }
    }
    
    return result;

}
