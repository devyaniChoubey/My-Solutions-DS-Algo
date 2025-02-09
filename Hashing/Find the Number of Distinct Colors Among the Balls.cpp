https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballToColor;
        unordered_map<int,int>colToFreq;
        vector<int>ans;

        for(auto &it:queries){
            int ball = it[0];
            int color = it[1];
            
            if(ballToColor.find(ball) != ballToColor.end()){
                int prevColor = ballToColor[ball];
                colToFreq[prevColor]--;

                if(colToFreq[prevColor] == 0) colToFreq.erase(prevColor);
            }
            colToFreq[color]++;
            ballToColor[ball] = color;
            
            ans.push_back(colToFreq.size());
        }

        return ans;
    }
};