https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/?envType=daily-question&envId=2024-12-29

class Solution {
public:
    int MOD = 1e9+7;
    long long solve(int wordsIndex, int targetInd, vector<string>& words, string &target,vector<vector<int>>&dp,vector<vector<int>>&count){
        if(targetInd >= target.size()) return 1;
        if(wordsIndex >= words[0].size()) return 0;

        if(dp[wordsIndex][targetInd] != -1) return dp[wordsIndex][targetInd]% MOD;

        long long pick = count[wordsIndex][target[targetInd]-'a']*solve(wordsIndex+1, targetInd+1, words, target,dp,count);
        long long notPick = solve(wordsIndex+1, targetInd, words, target,dp,count);

        return dp[wordsIndex][targetInd] = (pick + notPick)% MOD;
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>dp(words[0].size()+1 , vector<int>(target.size()+1 , -1));
        vector<vector<int>>count(words[0].size()+1, vector<int>(26, 0));

        for(int j=0;j < words[0].size();j++){
            for(int i=0;i < words.size();i++){
                count[j][words[i][j] - 'a']++;
            }
        }
        return solve(0, 0, words, target,dp, count);
    }
};