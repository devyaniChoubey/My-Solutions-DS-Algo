https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        vector<vector<int>>ans;

        for(int i=0;i < n-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int low = j+1, high = n-1;

                while(low < high){
                    long long sum = (long)nums[low] + (long)nums[high] + (long)nums[i] + (long)nums[j];
                    if(sum > target){
                        high--;
                    }else if(sum < target) low++;
                    else{
                        ans.push_back({nums[i], nums[j] , nums[low] , nums[high]});
                        low++;high--;
                        
                        while(low < high && nums[low] == nums[low-1]) low++;
                        while(low < high && nums[high] == nums[high+1]) high--;
                    }
                }
            }
        }

        return ans;
    }
};