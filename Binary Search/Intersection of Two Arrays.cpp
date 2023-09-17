
https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();

        set<int>st1, st2;

        
        for(int i=0;i < n1;i++) st1.insert(nums1[i]);

        for(int i=0;i < n2;i++) {
            if(st1.find(nums2[i]) != st1.end()){
                st2.insert(nums2[i]);
            }
        }

        vector<int>ans(st2.size());
        int j = 0;

        for(auto it:st2){
            ans[j++] = it;
        }

        return ans;

    }
};


//Binary search

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n1 = nums1.size(), n2 = nums2.size();

        vector<int>ans(n1+n2);
        int j = 0;
        
        for(int i=0;i < nums2.size();i++){
            int ind = lower_bound(nums1.begin() , nums1.end(), nums2[i]) - nums1.begin();
            cout << ind;
            if((i > 0 && nums2[i] != nums2[i-1]) || i == 0){
                if(ind != nums1.size() && nums1[ind] == nums2[i]) {
                    ans[j] = nums2[i];
                    j++;
                }
            }
        }

        ans.resize(j);

        return ans;

    }
};