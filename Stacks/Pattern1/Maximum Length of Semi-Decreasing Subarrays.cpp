https://leetcode.com/problems/maximum-length-of-semi-decreasing-subarrays/description/

https://leetcode.com/problems/maximum-length-of-semi-decreasing-subarrays/solutions/4258235/c-monotonic-stack-easy-to-understand-just-do-a-dry-run/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        int ans = 0;

        for(int i=n-1;i >= 0;i--){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }

        for(int i=0;i < n;i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                ans = max(ans, st.top() - i + 1);
                st.pop();
            }
        }

        return ans;
    }
};