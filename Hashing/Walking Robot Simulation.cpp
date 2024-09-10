https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>>directions = {{0, 1}, {1, 0} , {0, -1} , {-1, 0}};
        unordered_map<int,unordered_set<int>>hash;

        for(auto obstacle:obstacles){
            hash[obstacle[0]].insert(obstacle[1]);
        }

        int dir = 0;
        int x = 0, y = 0;
        int maxDist = 0;
        
        for(int i=0;i < commands.size();i++){
            if(commands[i] == -1){
                dir = (dir+1)%4;
            }else if(commands[i] == -2){
                dir = (dir+3)%4;
            }else{
                
                if(hash.find(x) != hash.end()){
                    if(hash[x].count(y)) {
                        if(x == 0 && y == 0) {}
                        else continue;
                    }
                }
                for(int j=0;j < commands[i];j++){
                    int tempX = x, tempY = y;
                    x += directions[dir].first;
                    y += directions[dir].second;
                    if(hash.find(x) != hash.end()){
                        if(hash[x].count(y)) {
                           x = tempX;
                           y = tempY;
                           break;
                        }
                    }
                }
            }

            maxDist = max(maxDist, (x*x) + (y*y));
        }

        return maxDist;

    }
};