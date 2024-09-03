https://leetcode.com/problems/longest-consecutive-sequence/description/


//Method 1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin() , nums.end());

        int maxLen = 1;
        int len = 1;

        for(int i=1;i < nums.size();i++){
            if(nums[i] == nums[i-1] + 1) len++;
            else if(nums[i] != nums[i-1]){
               maxLen = max(len, maxLen);
               len = 1;
            }
        }
        maxLen = max(len, maxLen);

        return maxLen;
    }
};


//Method 2

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());

        int best = 0;

        for(auto x:nums){
            if(numSet.find(x - 1) == numSet.end()){
                int y = x;
                while(numSet.find(y) != numSet.end()){
                    y++;
                }

                best = max(best , y - x);
            }
        }

        return best;


    }
};