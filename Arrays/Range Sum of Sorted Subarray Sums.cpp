https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sumArray(((n*(n+1))/2) , 0);
        int k = 0;

        for(int i=0;i < n;i++){
            int sum = 0;
            for(int j=i;j < n;j++){
               sum += nums[j];
               sumArray[k++] = sum;
            }
        }

        sort(sumArray.begin() , sumArray.end());

        long long ans = 0;

        for(int i=left-1;i < right;i++) ans = (ans+sumArray[i])%1000000007;;
        

        return ans;

    }
};