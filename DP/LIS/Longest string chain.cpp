https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
    bool static comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    bool compareFun(string s1, string s2){
        if(s1.length() != s2.length() + 1) return false;
        
        int i=0,j=0;
        while(i < s1.length()){
            if(s1[i] == s2[j]){
                i++;j++;
            }else{
                i++;
            }
        }

        if(i == s1.length() && j == s2.length()) return true;

        return false;
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int>dp(n+1, 1);

        int maxi = 0;
        for(int ind=0;ind < n;ind++){
            for(int prev=0;prev < ind;prev++){
                if(compareFun(words[ind], words[prev])){
                    if(dp[ind] < dp[prev] + 1){
                        dp[ind] = dp[prev] + 1;
                    }
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
};