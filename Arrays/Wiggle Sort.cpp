https://leetcode.com/problems/wiggle-sort/?envType=company&envId=google&favoriteSlug=google-thirty-days&difficulty=MEDIUM&status=TO_DO

//TC O(nlogn)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        for(int i=1;i < n-1;i+=2){
            swap(nums[i] , nums[i+1]);
        }

        
    }
};


// TC O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i < n-1;i++){
            if(i % 2 == 0 && nums[i+1] < nums[i]) swap(nums[i+1], nums[i]);
            else if(i % 2 == 1 && nums[i+1] > nums[i]) swap(nums[i+1], nums[i]);
        }
    }
};