
https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>count_map;

        int n = nums.size();

        for(auto it:nums) count_map[it]++;

        vector<int>res;

        vector<int>bucket[n+1];

        for(auto it:count_map){
            bucket[it.second].push_back(it.first);
        }

        for(int i=n;i >= 0;i--){
            if(bucket[i].size() > 0 && res.size() < k){
                res.insert(res.end() , bucket[i].begin() , bucket[i].end());
            }
        }

        return res;

        
    }
};