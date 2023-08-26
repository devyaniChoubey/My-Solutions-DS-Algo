https://leetcode.com/problems/jump-game-ii/description/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, maxReach = 0, curReach = 0;
        for(int i=0;i < n-1;i++){
            maxReach = max(maxReach, i + nums[i]);
            // we have to take jump now because our currjump now ends
            if(i == curReach){
                jumps++;
                curReach = maxReach;
            }

            if(curReach >= n-1){
                break;
            }
        }

        if(curReach < n - 1) return -1;
        return jumps;

    }
};