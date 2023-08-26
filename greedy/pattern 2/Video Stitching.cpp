https://leetcode.com/problems/video-stitching/description/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        vector<int>maxJump(101, 0);

        for(int i=0;i < clips.size(); i++){
            int start = clips[i][0];
            int end = clips[i][1];
            maxJump[start] = max(maxJump[start] , end);
        }

        int cur_reach = 0, furthest_reach = 0, clipsCnt = 0;
        
        for(int i=0;i < time;i++){
            furthest_reach = max(furthest_reach, maxJump[i]);

            if(i == cur_reach){
                clipsCnt++;
                cur_reach = furthest_reach;
            }
        }

        if(cur_reach < time) return -1;

        return clipsCnt;
    }
};