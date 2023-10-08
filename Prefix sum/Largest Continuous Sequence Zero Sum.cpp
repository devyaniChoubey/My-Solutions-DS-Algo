https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &nums) {
    unordered_map<int, int>sumToIndex;
    int sum = 0;
    int maxLen = 0;
    int n = nums.size();
    int endIdx = 0;
    
    for(int i=0;i < n;i++){
        int curLen = 0;
        
        sum += nums[i];
        
        if(nums[i] == 0) curLen = 1;
        
        if(sum == 0) curLen = i+1;
        
        if(sumToIndex.find(sum) != sumToIndex.end()){
            int prevInd = sumToIndex[sum];
            
            if(i - prevInd > curLen){
                curLen = i - prevInd;
            }
        }else sumToIndex[sum] = i;
        
        if(curLen > maxLen){
            maxLen = curLen;
            endIdx = i;
        }
    }
    
    vector<int>result;
    
    for(int i=endIdx - maxLen + 1;i <= endIdx;i++) result.push_back(nums[i]);
    
    return result;
    
}
