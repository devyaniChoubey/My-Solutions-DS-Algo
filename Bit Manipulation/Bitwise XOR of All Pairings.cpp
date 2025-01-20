https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int result = 0;

        if(n1 % 2 != 0){
            for(auto &it:nums2) result ^= it;
        }

        if(n2 % 2 != 0){
            for(auto &it:nums1) result ^= it;
        }

        return result;
    }
};