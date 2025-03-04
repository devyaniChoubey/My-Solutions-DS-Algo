https://leetcode.com/problems/construct-smallest-number-from-di-string/?envType=daily-question&envId=2025-02-18

class Solution {
public:
    bool solve(int ind, string &pattern, string &temp,vector<int>&vis){
        if(ind == pattern.size()+1) return true;

        for(char i='1';i <= '9';i++){
            if(vis[i-'0']) continue;
            if(ind > 0){
                if(pattern[ind-1] == 'I'){
                    if(i <= temp[ind-1]) continue;
                }else if(pattern[ind-1] == 'D'){
                    if(i >= temp[ind-1]) continue;
                }
            }

            temp.push_back(i);
            vis[i-'0'] = 1;
            if(solve(ind+1, pattern, temp,vis)) return true;
            vis[i-'0'] = 0;
            temp.pop_back();
        }

        return false;
    }
    string smallestNumber(string pattern) {
        string temp = "";
        vector<int>vis(10, 0);
        solve(0, pattern, temp, vis);
        return temp;
    }
};