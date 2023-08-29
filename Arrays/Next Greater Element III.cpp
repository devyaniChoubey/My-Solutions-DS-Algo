https://leetcode.com/problems/next-greater-element-iii/description/

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        next_permutation(str.begin() , str.end());

        auto res = stoll(str);
       
        /*
        if n = 554321 (non increasing type)
        in this case next_permutation will return false and not modify str
        and res will be equal to str
        */ 

        if(res > INT_MAX || res <= n) return -1;
        else return res;
    }
};


//Using my next permutation

class Solution {
public:
    bool nextPermutation(string& nums) {
        int ind = -1;
        int n = nums.size();

        for(int i=n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return false;
        }

        for(int i=n-1;i > ind;i--){
            if(nums[i] > nums[ind]){
                swap(nums[i] , nums[ind]);
                break;
            }
        }

 
        reverse(nums.begin() + ind + 1, nums.end());
        
        // Successfully computed the next permutation
        return true;

    }

    int nextGreaterElement(int n) {
        string str = to_string(n);

        nextPermutation(str);

        auto res = stoll(str);


        if(res > INT_MAX || res <= n) return -1;
        else return res;
    }
};