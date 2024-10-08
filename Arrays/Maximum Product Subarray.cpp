// https://www.geeksforgeeks.org/maximum-product-subarray/
// https://leetcode.com/problems/maximum-product-subarray/


// Method 1
/*
Let me try to give some explanations for this solution.

Case 1: If there's no zero in the array
Then the subarray with maximum product must start with the first element or end with the last element. 
And therefore, the maximum product must be some prefix product or suffix product. 

Case 2: If there are zeros in the array
We can split the array into several smaller ones. 
That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead. 
And this is exactly what A[i] *= (A[i - 1]) or 1 does.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;

        int ans = INT_MIN;

        int n = nums.size();

        for(int i=0;i < n;i++){
            suffix *= nums[n - 1 - i];
            prefix *= nums[i];

            ans = max(ans, max(suffix, prefix));
            
            if(suffix == 0) suffix = 1;
            if(prefix == 0) prefix = 1;

        }

        return ans;
    }
};