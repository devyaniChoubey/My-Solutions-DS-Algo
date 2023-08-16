https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++) mp[nums1[i]] = i;
        
        vector<int> ng(nums1.size(), -1); // Initialize with -1
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();

            if (!st.empty()){
                if(mp.find(nums2[i]) != mp.end())ng[mp[nums2[i]]] = st.top();
            }

            st.push(nums2[i]);
        }

        return ng;
    }
};