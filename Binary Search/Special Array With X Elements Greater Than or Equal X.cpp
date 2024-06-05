https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        for(int i=0;i <= n;i++){
            int ind = lower_bound(nums.begin(), nums.end(), i) - nums.begin();

            if(n - ind == i)return i;
        }

        return -1;
    }
};



class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>freq(n+1, 0);

        for(auto it:nums) freq[min(n, it)]++;

        int numbersGreaterThanEqualTo = 0;

        for(int i=n;i >= 0;i--){
            numbersGreaterThanEqualTo += freq[i];

            if(numbersGreaterThanEqualTo == i) return i;
        }

        return -1;
    }
};