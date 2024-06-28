https://leetcode.com/problems/minimum-area-rectangle/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {


        unordered_map<int, unordered_set<int>>mp;

        for(auto it:points){
            mp[it[0]].insert(it[1]);
        }

        int n = points.size();

        int area = 1e9;

        for(int i=0;i < n;i++){
            int x1 = points[i][0] , y1 = points[i][1];
            for(int j=i+1;j < n;j++){
                int x2 = points[j][0] , y2 = points[j][1];

                if(mp[x1].count(y2) && mp[x2].count(y1) > 0 && x1 != x2 && y1 != y2){
                    area = min(area, abs(y2-y1)*abs(x2-x1));
                }
            }
        }

        if(area == 1e9)return 0;
        else return area;
        
    }
};