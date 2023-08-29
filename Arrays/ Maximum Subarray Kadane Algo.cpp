https://leetcode.com/problems/maximum-subarray/description/

//Kadane algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        int n = nums.size();
        for(int i=0;i < n;i++){
            sum += nums[i];
            maxi = max(sum, maxi);
            if(sum < 0) sum = 0;
        } 

        return maxi;
    }
};



//Print max sum subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int start = -1, ansStart = -1, ansEnd = -1;

        int n = nums.size();
        for(int i=0;i < n;i++){
            if(sum == 0) start = i;
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0) sum = 0;
        } 

        for(int i=0;i < n;i++){
          if(i >= ansStart && i <= ansEnd) cout << nums[i] << " ";

        }

        return maxi;
    }
};