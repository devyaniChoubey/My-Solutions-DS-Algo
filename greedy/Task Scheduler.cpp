https://leetcode.com/problems/task-scheduler/description/?envType=list&envId=oqv95d22


https://leetcode.com/problems/task-scheduler/editorial/?envType=list&envId=oqv95d22
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        int maxFreq =  INT_MIN;
        int cntMaxFreq = 0;

        for(char it:tasks){
            freq[it-'A']++;
            maxFreq = max(maxFreq, freq[it-'A']);
        }

        for(auto it: freq){
            if(it == maxFreq) cntMaxFreq++;
        }

        int ans = tasks.size();

        ans = max(ans , ((n+1)*(maxFreq - 1) + cntMaxFreq));

        return ans;
    }
};