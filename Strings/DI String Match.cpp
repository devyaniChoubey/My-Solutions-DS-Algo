https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int min = 0;
        int n = s.length();
        int max = n;
        
        vector<int>ans(n+1, 0);
        int k = 0;

        for(int i=0;i < n;i++){
            if(s[i] == 'I') {
                ans[k++] = min;
                min++;
            }else if(s[i] == 'D') {
                ans[k++] = max;
                max--;
            }
        }

        ans[n] = min;
        return ans;
    }
};