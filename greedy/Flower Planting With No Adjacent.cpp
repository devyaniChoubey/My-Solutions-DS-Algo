https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n];

        for(auto path:paths){
            adj[path[0] - 1].push_back(path[1] - 1);
            adj[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int>res(n, 0);

        for(int i=0;i < n;i++){
            vector<int>used(5, 0);

            for(int adjNode:adj[i]){
                //Mark the color as used if neighbor has used it before
                used[res[adjNode]] = 1;
            }

            //Now just use a color that has not been used yet
            for(int j=1;j <= 4;j++){ //used[c] == 0 => the color has not been used yet,
               if(used[j] == 0) 
                res[i] = j; //so let's use that one
            }
        }

        return res;
    }
};