https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;

        int maxWater = INT_MIN;

        while(left < right){
            maxWater = max(maxWater, (right - left)*min(height[left] , height[right]));
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
 
        return maxWater;

    }
};