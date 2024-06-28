https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        vector<int>ans;

        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else j++;
        }

        return ans;
    }
};




class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int>ans;

        unordered_map<int,int>freq;

        for(auto &it:nums2) freq[it]++;

        for(auto &it:nums1){
            if(freq[it] > 0) {
                ans.push_back(it);
                freq[it]--;
            }
        }
        return ans;
    }
};