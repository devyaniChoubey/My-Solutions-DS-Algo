https://leetcode.com/problems/subarray-sum-equals-k/description/


//TLE

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i < n;i++){
            int sum = nums[i];

            if(sum == k) ans++;
            for(int j=i+1;j < n;j++){
                sum += nums[j];
                if(sum == k) ans++;
            }
        }

        return ans;
    }
};



//Prefix Sum

https://leetcode.com/problems/subarray-sum-equals-k/solutions/1759909/c-full-explained-every-step-w-dry-run-o-n-2-o-n-two-approaches/

If anyone is confused why the count was increased by myMap[ curr - k ] instead of just count+=1 .
 It was because prefix sum can be same because of some negative values in the array. 
so out next occuring k will also pair with those negative values also .

consider this case A : [3 4 7 2 -3 1 4 2 1 ]
preSum : [3 7 14 16 13 14 18 20 21]

you can see 14 occured twice because of the subsequence [2 -3 1] their sum is 0. so When you are at the final index with value 1 . 
you have curr - k = 21 - 7 = 14 . you check for 14 it has occured twice . so you need to consider subsequences [2 -3 1 4 2 1] and [4 2 1] 


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n, 0);

        prefix[0] = nums[0];

        for(int i=1;i < n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int , int>mp;

        int ans = 0;

        for(int i=0;i < n;i++){
            if(prefix[i] == k) ans++;

            if(mp.find(prefix[i] - k) != mp.end()){
                ans += mp[prefix[i] - k];
            }

            mp[prefix[i]]++;
        }

        return ans;
    }
};


//o(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mp;
        for(int i=0;i < n;i++){
           sum += nums[i];
           if(sum == k) ans++;

           if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
           }

           mp[sum]++;
        }

        return ans;
    }
};