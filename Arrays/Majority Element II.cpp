https://leetcode.com/problems/majority-element-ii/description/

Boyer-Moore Majority Vote algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int element1 = -1 , element2 = -1;

        int n = nums.size();

        for(int i=0;i < n;i++){
            if(cnt1 == 0 && nums[i] != element2){
                cnt1 = 1;
                element1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != element1){
                cnt2 = 1;
                element2 = nums[i];
            }else if(nums[i] == element1) cnt1++;
            else if(nums[i] == element2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i=0;i < n;i++){
           if(nums[i] == element1) cnt1++;
           else if(nums[i] == element2) cnt2++;
        }

        vector<int>ans;

        if(cnt1 > n/3) ans.push_back(element1);
        if(cnt2 > n/3) ans.push_back(element2);

        return ans;
    }
};


