https://leetcode.com/problems/majority-element/description/


Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int majElement;

        int n = nums.size();

        for(int i=0;i < n;i++){
            if(cnt == 0){
                majElement = nums[i];
                cnt = 1;
            }else if(nums[i] == majElement){
               cnt++;
            }
            
            if(nums[i] != majElement) cnt--;
        }

        return majElement;
    }
};



//if majority element might not exist

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int majElement;

        int n = nums.size();

        for(int i=0;i < n;i++){
            if(cnt == 0){
                majElement = nums[i];
                cnt = 1;
            }else if(nums[i] == majElement){
               cnt++;
            }
            
            if(nums[i] != majElement) cnt--;
        }

        int cnt1 = 0;

        //check count of majority element

        for(int i=0;i < n;i++){
            if(nums[i] == majElement){
               cnt1++;
            }
        }

        if(cnt1 > n/2)return majElement;
        else return -1;
    }
};