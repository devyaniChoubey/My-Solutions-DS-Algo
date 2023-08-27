https://leetcode.com/problems/two-sum/description/

//2 Pointers

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>>v;
        for(int l=0;l < nums.size();l++){
            v.push_back({nums[l], l});
        }

        sort(v.begin() , v.end());

        int l = 0, r = nums.size() - 1;

        while(l < r){
            if(v[l].first + v[r].first == target) return {v[l].second, v[r].second};
            if(v[l].first + v[r].first > target) r--;
            else if(v[l].first + v[r].first < target) l++;
        }

        return {};
    }
};