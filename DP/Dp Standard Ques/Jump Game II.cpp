https://leetcode.com/problems/jump-game-ii/description/


//Recursive
class Solution {
public:
    int solve(int ind, vector<int>& nums) {
        int n = nums.size();
        if(ind >= n-1) return 0;

        int minJumps = 1e9;
        for(int k=ind+1; k <= (ind+nums[ind]); k++){
            int jumps = 1 + solve(k, nums);
            minJumps = min(jumps, minJumps);
        }

        return minJumps;
    }
    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};


//Memoised

class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>&dp) {
        int n = nums.size();
        if(ind >= n-1) return 0;

        if(dp[ind] != -1) return dp[ind];
        int minJumps = 1e9;
        for(int k=ind+1; k <= (ind+nums[ind]); k++){
            int jumps = 1 + solve(k, nums, dp);
            minJumps = min(jumps, minJumps);
        }

        return dp[ind] = minJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};


// Method 3: Time = O(n), Space = O(1)
// https://youtu.be/a9r98S-pDvk

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curReach = 0, maxReach = 0;

        /*
        We are taking jump from 0th index to the range maxReach
        
        curReach = we can take jump from particular index
        maxReach = we cango up to maximum
        jumps = to count no. of jumps
        */

        // NOTE: < n-1
        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            // we have to take jump now because our currjump now ends
            if (i == curReach) {
                jumps++;
                curReach = maxReach;
            }
            if (curReach >= n - 1) {
                break;
            }
        }

        if (curReach < n - 1) return -1;
        return jumps;
    }
};
