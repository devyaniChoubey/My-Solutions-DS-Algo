
https://leetcode.com/problems/xor-queries-of-a-subarray/?envType=daily-question&envId=2024-09-13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>xorPrefix(n, 0);
        
        xorPrefix[0] = arr[0];

        for(int i=1;i < arr.size();i++){
            xorPrefix[i] = xorPrefix[i-1]^arr[i];
        }

        vector<int>ans;

        for(int i=0;i < queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];

            if(l != 0)ans.push_back(xorPrefix[r]^xorPrefix[l-1]);
            if(l == 0)ans.push_back(xorPrefix[r]);
        }

        return ans;
    }
};