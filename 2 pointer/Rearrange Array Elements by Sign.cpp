
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

//Brute
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>positive;
        vector<int>negative;

        for(int i=0;i < n;i++){
            if(nums[i] >= 0) positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }

        vector<int>ans;

        for(int i=0;i < n/2;i++){
           ans.push_back(positive[i]);
           ans.push_back(negative[i]);
        }

        return ans;
    }
};


//2 pointer

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n , 0);

        int negInd = 1, posInd = 0;

        for(int i=0;i < n;i++){
            if(nums[i] < 0){
                ans[negInd] = nums[i];
                negInd+=2;
            }else{
                ans[posInd] = nums[i];
                posInd+=2;
            }
        }

        return ans;
    }
};