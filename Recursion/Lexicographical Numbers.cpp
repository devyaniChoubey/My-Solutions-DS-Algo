https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    void solve(int ind, int n,vector<int>&ans){
        
        for(int i=0;i <= 9;i++){
            if(ind == 0 && i == 0) continue;

            int newN = ind*10+i;
            if(newN > n) return;
            ans.push_back(newN);
            solve(newN, n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        solve(0, n,ans);
        return ans;
    }
};