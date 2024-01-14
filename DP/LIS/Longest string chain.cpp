https://leetcode.com/problems/longest-string-chain/description/

//Approach 1

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


//Approach 2

class Solution {
public:
    bool isPredecessor(string &a, string &b){
        int i=0,j=0;

        while(j < b.length()){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        if(i == a.length() && j == b.length()){
            return true;
        }else return false;

    }
    int solve(int prevInd, int ind, vector<string>& words,vector<vector<int>>&dp){
        if(ind >= words.size()) return 0;

        int pick = -1e9;

        if(dp[prevInd+1][ind] != -1) return dp[prevInd+1][ind];

        if(prevInd == -1){
            pick = 1 + solve(ind, ind+1, words,dp);
        }else if(words[prevInd].size() + 1 == words[ind].size() && isPredecessor(words[prevInd], words[ind])){
            pick = 1 + solve(ind, ind+1, words,dp);
        }

        int notPick = solve(prevInd, ind+1, words,dp);

        return dp[prevInd+1][ind] = max(pick, notPick);
    }
    bool static sortByLen(string &a, string &b){
        return (a.length() < b.length());
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin() , words.end() , sortByLen);

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solve(-1, 0, words,dp);
    }
};