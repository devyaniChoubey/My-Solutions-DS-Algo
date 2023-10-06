https://leetcode.com/problems/max-consecutive-ones-iii/description/

https://leetcode.com/problems/max-consecutive-ones-iii/editorial/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int,int>mp;
        int left = 0, right = 0;
        int n = nums.size();
        int len = 0;

        while(right < n){
            mp[nums[right]]++;
            while(mp[0] > k){
                mp[nums[left]]--;
                left++;
            }

            len = max(right - left + 1, len);
            right++;
        }

        return len;
    }
};



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        
        while(right < n){
            if(nums[right] == 0) k--;

            if(k < 0){
                k += 1 - nums[left];
                left++;
            }

            right++;
        }

        return right - left;
    }
};