https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

//Brute Force

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        int n = nums.size();
        for(int i=0;i < n;i++){
            s.insert(nums[i]);
        }

        int index = 0;
        for(auto it:s){
            nums[index] = it;
            index++;
        }
        return s.size();
    }
};



//2 pointer

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        for(int j=1;j < n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for(int j=0;j < n;j++){
            if(j == 0 || (nums[j] != nums[j-1])){
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};