https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/

class Solution {
public:
    void dfs(int num, int k, int n, vector<int>&ans){
        if(n == 0) {
            ans.push_back(num);
            return;
        }

        int node = num%10;

        if(0 <= node+k && node+k <= 9){
            int temp = num*10 + (node+k);
            dfs(temp, k, n-1, ans);
        }

        if(k != 0 && 0 <= node-k && node-k <= 9){
            int temp = num*10 + (node-k);
            dfs(temp, k, n-1, ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int num=1;num <= 9;num++){
            dfs(num, k, n-1, ans);
        }

        return ans;
    }
};