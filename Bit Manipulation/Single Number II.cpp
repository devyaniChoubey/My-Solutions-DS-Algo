https://leetcode.com/problems/single-number-ii/description/


//Solution 1

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>freq;

        for(int num:nums){
            freq[num]++;
        }

        for(auto it:freq){
            if(it.second == 1) return it.first;
        }

        return -1;
    }
};

//Solution 2

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bitIndex=0;bitIndex < 32;bitIndex++){
            long long cnt = 0;

            for(int i=0;i < nums.size();i++){
                cnt += (nums[i] & (1 << bitIndex));
            }

            if(cnt% 3 != 0) ans += (1 << bitIndex);
        }      

        return ans;            
    }
};


//SOLUTION 3

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans;
        bool ansFound = false;
        for(int i=1;i < nums.size();i+=3){
            if(nums[i] != nums[i-1]){
                ansFound = true;
                ans = nums[i-1];
                break;
            }
        } 

        if(!ansFound) return nums[nums.size()-1]; 

        return ans;    
    }
};

//solution 4

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int one = 0;
        int two = 0;

        for(int i=0;i < nums.size();i++){
            one = (one^nums[i]) & (~two);
            two = (two^nums[i]) & (~one);
        } 

        return one; 
    }
};