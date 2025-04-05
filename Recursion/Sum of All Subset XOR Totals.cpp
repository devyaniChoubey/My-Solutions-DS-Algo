https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2025-04-05

class Solution {
    public:
    
        int solve(int i, vector<int>& nums, int cur){
            if(i >= nums.size()) {
                return cur;
            }
    
            int pick = solve(i+1, nums, cur^nums[i]);
            int notPick = solve(i+1, nums, cur);
    
            return pick + notPick;
        }
    
        int subsetXORSum(vector<int>& nums) {
            return solve(0, nums, 0);
        }
    };