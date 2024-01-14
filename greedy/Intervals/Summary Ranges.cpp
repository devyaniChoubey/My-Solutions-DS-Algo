https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;

        if(nums.size() == 0) return ans;

        int minEl = nums[0];
        int maxEl = nums[0];

        for(int i=1;i < nums.size();i++){
            if(nums[i] == nums[i-1] + 1){
                maxEl = nums[i];
            }else{
                if(minEl == maxEl)ans.push_back(to_string(minEl));
                else ans.push_back(to_string(minEl)+ "->" + to_string(maxEl));
                minEl = nums[i];
                maxEl = nums[i];
            }
        }

        if(minEl == maxEl)ans.push_back(to_string(minEl));
        else ans.push_back(to_string(minEl)+ "->" + to_string(maxEl));

        return ans;
    }
};