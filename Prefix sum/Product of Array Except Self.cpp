https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffix(n, 1);
        int prefix = 1;

        suffix[n-1] = nums[n-1];

        for(int i=n-2;i >= 0;i--){
            suffix[i] = suffix[i+1]*nums[i];
        } 

        vector<int>ans(nums.size());
        int i=0;

        for(int i=0;i < n-1;i++){
            ans[i] = prefix*suffix[i+1];
            prefix *= nums[i];
        }

        ans[n-1] = prefix;

        return ans;
    }
};

//Method 2


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>ans(n, 1);

        ans[0] = 1;

        for(int i=1;i < n;i++) ans[i] = ans[i-1]*nums[i-1];

        int suffix = 1;

        for(int i=n-1;i >= 0;i--){
            ans[i] = suffix*ans[i];
            suffix *= nums[i];
        }

        return ans;

    }
};