https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description/

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int minEl = INT_MAX;
        int maxEl = INT_MIN;

        int minInd, maxInd;

        for(int i=0;i < n;i++){
            if(minEl > nums[i]){
                minInd = i;
                minEl = nums[i];
            }

            if(maxEl <= nums[i]){
                maxInd = i;
                maxEl = nums[i];
            }
        }

        if(maxInd < minInd) return minInd+n-1-maxInd-1;
        else return minInd+n-1-maxInd;
    }
};