https://leetcode.com/problems/contiguous-array/description/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>sumToIndex;
        int n = nums.size();

        int sum = 0;
        int maxLen = 0;


        sumToIndex[0] = -1;

        for(int i=0;i < n;i++){
            if(nums[i] == 0) nums[i] = -1;

            sum += nums[i];

            if(sumToIndex.find(sum) != sumToIndex.end()){
                maxLen = max(maxLen, i - sumToIndex[sum]);
            }else sumToIndex[sum] = i;
        }

        return maxLen;
    }
};