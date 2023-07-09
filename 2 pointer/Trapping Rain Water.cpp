https://leetcode.com/problems/trapping-rain-water/


//Brute Force 
//TLE

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        for(int i=0;i < n;i++){
            int leftMax = 0;
            int rightMax = 0;
            for(int j=0;j <= i;j++){
                leftMax = max(leftMax, height[j]);
            }

            for(int j=i;j <= n-1;j++){
                rightMax = max(rightMax, height[j]);
            }
 
            totalWater += (min(leftMax, rightMax) - height[i]  > 0) ? min(leftMax, rightMax) - height[i] : 0;

        }

        return totalWater;
    }
};


//Better
//Accepted

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0, leftMax = 0, rightMax = 0;
        vector<int>prefix(n, 0) , suffix(n, 0);
        for(int i=0;i < n;i++){
            prefix[i] = max(leftMax, height[i]);
            leftMax = prefix[i];
        }

        for(int i=n-1;i >= 0;i--){
            suffix[i] = max(rightMax, height[i]);
            rightMax = suffix[i];
        }

        for(int i=0;i < n;i++){
            int cur = min(suffix[i], prefix[i]) - height[i];
            totalWater += max(cur, 0);
        }

        return totalWater;
    }
};


//Two pointer
//Optimised

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0, leftMax = 0, rightMax = 0;
        
        int l = 0, r = n - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] > leftMax) leftMax = height[l];
                else totalWater += (leftMax - height[l]);
                l++;
            }else{
                if(height[r] > rightMax) rightMax = height[r];
                else totalWater += (rightMax - height[r]);
                r--;
            }
        }

        return totalWater;
    }
};