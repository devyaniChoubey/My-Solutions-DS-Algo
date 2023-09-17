https://leetcode.com/problems/random-pick-with-weight/description/

https://leetcode.com/problems/random-pick-with-weight/editorial/


in (rand() % x) + 1;  why +1
A simple explanation -

 (rand() % x) will return value from 0 to X-1

As there is no 0 weight, we need to +1 to avoid getting 0 from the random function.

+1 will make the range as 1 to X, which is exactly the real range we need.

class Solution {
public:
    vector<int>prefixSum;
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);

        for(int i=1;i < w.size();i++){
            prefixSum.push_back(prefixSum[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        int x = prefixSum.back();
        int index = (rand() % x) + 1;

        int ans = lower_bound(prefixSum.begin() , prefixSum.end() , index) - prefixSum.begin();

        return ans;
        
    }
};
