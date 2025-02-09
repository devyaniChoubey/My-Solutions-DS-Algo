https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i < n;i++){
            for(int j=i+1;j < n;j++){
                freq[nums[i]*nums[j]]++;
            }
        }

        int ans = 0;

        for(auto &it:freq){
            int product = it.first, cnt = it.second;

            ans += (8*((cnt*(cnt-1))/2));
        }

        return ans;


    }
};