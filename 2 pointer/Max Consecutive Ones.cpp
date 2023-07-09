https://leetcode.com/problems/max-consecutive-ones/description/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int cnt = 0;
        for(int i=0;i < nums.size();i++){
            if(nums[i] == 1) cnt++;
            else {
                maxLen = max(maxLen, cnt);
                cnt = 0;
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
}; 