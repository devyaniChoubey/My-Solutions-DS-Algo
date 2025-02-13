https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/?envType=daily-question&envId=2025-02-12

class Solution {
public:
    int digitSum(int num){
        int sum = 0;

        while(num != 0){
            sum += (num%10);
            num = num/10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = -1;

        for(int i=0;i < nums.size();i++){
            int sum = digitSum(nums[i]);

            if(mp.count(sum)){
                ans = max(ans, mp[sum] + nums[i]);
                mp[sum] = max(mp[sum], nums[i]);
            }else mp[sum] = nums[i];
        }

        return ans;


    }
};