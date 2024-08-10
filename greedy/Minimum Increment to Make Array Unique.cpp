https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int moves = 0;

        for(int i=1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                nums[i]++;
                moves++;
            }else if(nums[i] < nums[i-1]){
                moves += abs(nums[i] - nums[i-1] - 1);
                nums[i] = nums[i-1] + 1;
            }
        }

        return moves;
    }
};


//Solution 2

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int moves = 0;

        for(int i=1;i < nums.size();i++){
            if(nums[i] <= nums[i-1]){
                moves += abs(nums[i] - nums[i-1] - 1);
                nums[i] = nums[i-1] + 1;
            }
        }

        return moves;
    }
};


//solution 3

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for(auto &it:nums) maxi = max(maxi, it);

        vector<int>freqCount(n+maxi+1, 0);

        for(auto &it:nums){
            freqCount[it]++;
        }

        int moves = 0;
        int carry = 0;

        for(int i=0;i < freqCount.size();i++){
            carry += freqCount[i] - 1;
            if(carry <= 0){
                if(carry == -1) carry = 0;
                continue;
            }
            moves += carry;
            freqCount[i] = 1;
        }

        return moves;
    }
};