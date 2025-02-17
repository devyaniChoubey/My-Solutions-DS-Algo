https://leetcode.com/problems/letter-tile-possibilities/


class Solution {
public:
    int solve(vector<int>&freq, string &tiles){
        int ans = 0;

        for(int i=0;i < 26;i++){
            if(freq[i] == 0) continue;
            ans++;

            freq[i]--;
            ans+=solve(freq, tiles);
            freq[i]++;
        } 

        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26, 0);

        for(char &c:tiles) freq[c-'A']++;

        return solve(freq, tiles);
    }
};