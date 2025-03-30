https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>>temp1, temp2;
    
            for(auto &it:rectangles){
                int x1 = it[0] , y1 = it[1] , x2 = it[2], y2 = it[3];
    
                temp1.push_back({x1 , x2});
                temp2.push_back({y1 , y2});
            }
    
            sort(temp1.begin() , temp1.end());
            sort(temp2.begin() , temp2.end());
    
            int gapCount = 0, size = temp1.size();
            int last = temp1[0][1];
    
            for(int i=1;i < size;i++){
                if(temp1[i][0] >= last){
                    gapCount++;
                }
                last = max(last, temp1[i][1]);
            }
    
            if(gapCount >= 2) return true;
    
            gapCount = 0;
            last = temp2[0][1];
    
            for(int i=1;i < size;i++){
                if(temp2[i][0] >= last){
                    gapCount++;
                }
                last = max(last, temp2[i][1]);
            }
    
            if(gapCount >= 2) return true;
    
            return false;
        }
    
        
    };