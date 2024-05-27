https://leetcode.com/problems/number-of-arithmetic-triplets/


class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int mp[201] = {};
        int ans = 0;
        for(int i=0;i < nums.size();i++){
            int second = nums[i] - diff;
            int first = second - diff;

            if(first < 0 || second < 0) {
                mp[nums[i]] = true;
                continue;
            }

            ans += (mp[second] && mp[first]);

            mp[nums[i]] = true;
        
        }

        return ans;
    }
};