https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(auto &it:nums) freq[it]++;

        sort(nums.begin() , nums.end() , [&](auto &num1, auto &num2) {
            if(freq[num1] == freq[num2]) return num1 > num2;
            
            return freq[num1] < freq[num2];
        });

        return nums;
    }
};