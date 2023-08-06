
https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/

class Solution {
public:
    bool comp(vector<string>& A, int cur, int prev){
        for(int k=0;k < A.size();k++){
            if(A[k][prev] > A[k][cur]) return 0;
        }
        return 1;
    }
    int minDeletionSize(vector<string>& A) {
        int n = A[0].length();
        vector<int>dp(n+1, 1);
        int ans = 1;
        for(int i=0;i < n;i++){
            for(int prev=0;prev < i;prev++){
                if(comp(A, i, prev)){
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return n - ans;

    }
};


//Solution 2
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<int> dp(m, 1);
        int ans = 0;
        for(int col = 1; col < m; col++){
            for(int i = 0; i < col; i++) {
                bool isGood = true;
                for(int row = 0; row < n; row++) {
                    if (A[row][i] > A[row][col]) {
                        isGood = false;
                        break;
                    }
                }
                if (!isGood) continue;
                dp[col] = max(dp[col], dp[i] + 1);
            }
        }
        int maxLen = 0;
        for (int len : dp) maxLen = max(maxLen, len);
        return m - maxLen;
    }
};