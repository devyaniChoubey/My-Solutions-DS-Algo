https://leetcode.com/problems/4sum-ii/description/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int ,int>mp;

        for(int i:nums3){
            for(int j:nums4){
               mp[i+j]++;
            }
        }

        int cnt = 0;

        for(int i:nums1){
            for(int j:nums2){
               cnt += mp[-(i+j)];
            }
        }

        return cnt;
    }
};