https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1;i < n;i++){
           ans = ans^nums[i];
        }

        return ans;
    }
};



//Similar question
https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i=0;i < nums.size();i++){
           missing = missing^nums[i]^(i+1);
        }

        return missing;
    }
};