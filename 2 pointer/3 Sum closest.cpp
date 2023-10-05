https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &nums, int B) {
    sort(nums.begin() , nums.end());
    int n = nums.size();
    long long minDiff = 1e9;
    long long closestSum = 1e9;
    
    for(int i=0;i < n-2;i++){
        int left = i+1;
        int right = n-1;
        
        while(left < right){
            long long currSum = nums[i] + nums[left] + nums[right];
        
            long long curDiff = abs(currSum - B);
            
            if(curDiff < minDiff){
                minDiff = curDiff;
                closestSum = currSum;
            }
            
            if(currSum < B) left++;
            else right--;
        }
        
    }
    
    return (int)closestSum;
}

https://leetcode.com/problems/3sum-closest/description/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;
        int n = nums.size();

        for(int i=0;i < n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int curSum = nums[left] + nums[right] + nums[i];
                int curDiff = abs(target - curSum);

                if(curDiff < minDiff){
                    minDiff = curDiff;
                    closestSum = curSum;
                }

                if(curSum < target) left++;
                else right--; 
            }
        } 

        return closestSum;
    }
};