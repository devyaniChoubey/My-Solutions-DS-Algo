https://leetcode.com/problems/subarrays-with-k-different-integers/description/

Approach: To directly count the subarrays with exactly K different integers is hard but to find the count of subarrays with at most K different integers is easy. So the idea is to find the count of subarrays with at most K different integers, let it be C(K), and the count of subarrays with at most (K – 1) different integers,
 let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the required answer.
Count of subarrays with at most K different elements can be easily calculated through the sliding window technique. 
The idea is to keep expanding the right boundary of the window till the count of distinct elements in the window is less than or equal to K and when the count of distinct elements inside the window becomes more than K, 
start shrinking the window from the left till the count becomes less than or equal to K. Also for every expansion, keep counting the subarrays as right – left + 1 
where right and left are the boundaries of the current window.

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }

    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        map<int , int>mp;

        int left = 0, right = 0;
        int n = nums.size();
        int cnt = 0;

        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
               mp[nums[left]]--;
               if(mp[nums[left]] == 0) mp.erase(nums[left]);
               left++;
            }

            cnt += right - left + 1;

            right++;
        }

        return cnt;
    }
};