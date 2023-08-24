
https://leetcode.com/problems/maximum-product-of-three-numbers/description/


//TC O(n*logn)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[n-1]*nums[n-2]*nums[n-3] , nums[0]*nums[1]*nums[n-1]);
    }
};



//TC O(n)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // s1 smallest s2 second smallest;
        // l1 largest l2 second largest l3 third largest
        int s1 = INT_MAX , s2 = INT_MAX;
        int l1 = INT_MIN, l2 = INT_MIN , l3 = INT_MIN;

        for(int i=0;i < nums.size(); i++){
            if(nums[i] < s1){
                s2 = s1;
                s1 = nums[i];
            }else if(nums[i] < s2){
                s2 = nums[i];
            }

            if(nums[i] > l1){
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            }else if(nums[i] > l2){
                l3 = l2;
                l2 = nums[i];
            }else if(nums[i] > l3){
               l3 = nums[i];
            }
        }
        
        return max(l1*l2*l3, l1*s1*s2);

    }
};