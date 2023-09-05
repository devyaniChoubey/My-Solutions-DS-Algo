
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/solutions/457569/c-greedy/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        map<int ,int> freq;

        for(auto it:nums) freq[it]++;

        for(auto it:freq){
            
            if(it.second == 0) continue;

            int start = it.first;
            int curFreq = it.second;

            for(int i=0;i < k;i++){
               if(freq[it.first+i] < curFreq) return false;
               else freq[it.first+i] -= curFreq;
            }
            
        }

        return true;
    }
};


similar question https://leetcode.com/problems/hand-of-straights/description/