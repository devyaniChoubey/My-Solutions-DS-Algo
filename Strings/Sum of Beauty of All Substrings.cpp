https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        int ans = 0;

        
        for(int i=0;i < s.length();i++){
            int mp[26] = {};
            for(int j=i;j < s.length();j++){
                mp[s[j] - 'a']++;
                int maxFreq = 0, minFreq = INT_MAX; 
                for(auto it:mp){
                    maxFreq = max(maxFreq, it);
                    if(it > 0)minFreq = min(minFreq, it);
                }
                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};