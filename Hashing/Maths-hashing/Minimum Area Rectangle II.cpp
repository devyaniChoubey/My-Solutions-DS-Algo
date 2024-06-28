https://leetcode.com/problems/minimum-area-rectangle-ii/

class Solution {
public:
    double distanceSquare(auto &p1 , auto &p2){
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }
    double minAreaFreeRect(vector<vector<int>>& points) {

        unordered_set<string>seen;

        for(auto &p:points){
          seen.insert(to_string(p[0]) + " " + to_string(p[1]));
        }

        double area = 1e9;

        for(auto &p1:points){
            for(auto &p2:points){
                for(auto &p3:points){
                    if(distanceSquare(p1, p2) + distanceSquare(p2, p3) != distanceSquare(p1,p3)) continue;

                    int x = p1[0] + p3[0] - p2[0];
                    int y = p1[1] + p3[1] - p2[1];

                    if(seen.count(to_string(x) + " " + to_string(y))){
                        double curarea = sqrt(distanceSquare(p1, p2)) * sqrt(distanceSquare(p3, p2));
                        if(curarea != 0){
                            area = min(area, curarea);
                        }
                    }

                }
            }
        }

        if(area == 1e9)return 0.000;
        else return area;
    }
};