https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt[101] = {};

        for(auto& it:heights) cnt[it]++;
        int k = 0;
        int ans = 0;


        for(int i=1;i < 101;i++){
            for(int j=0;j < cnt[i];j++){
                if(i != heights[k]) ans++;
                k++;
            }
        }

        return ans;
    }
};