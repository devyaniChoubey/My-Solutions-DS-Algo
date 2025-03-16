https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15

class Solution {
    public:
        bool isValid(vector<int>& nums,int k, int mid){
            int n = nums.size(), ans = 0;
    
            for(int j= 0;j < n;j++){
                if(nums[j] <= mid) {
                    ans++;
                    j++;
                }
            }
    
            return (ans >= k);
        }
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            int left = *min_element(nums.begin() , nums.end()) , right = *max_element(nums.begin() , nums.end());
    
            while(left <= right){
                int mid = (left + right)/2;
    
                if(isValid(nums, k, mid)){
                    right = mid-1;
                }else {
                    left = mid+1;
                }
            }
    
            return left;
        }
    };