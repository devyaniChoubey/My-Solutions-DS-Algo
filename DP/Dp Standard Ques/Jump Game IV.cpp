https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>neighbours;
        for(int i=0;i < n;i++){
            neighbours[arr[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        vis[0] = 1;

        int level = 0;


        while(!q.empty()){
            int size = q.size();

            for(int i=0;i < size;i++){
                int node = q.front();
                q.pop();

                if(node == n-1) return level;

                if(node-1 >= 0 && vis[node-1] == 0){
                    q.push(node-1);
                    vis[node-1] = 1;
                }

                if(node+1 < n && vis[node+1] == 0){
                    q.push(node+1);
                    vis[node+1] = 1;
                }

                for(int it:neighbours[arr[node]]){
                    if(it != node && !vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
                // remove for next iterations since already visited
                neighbours[arr[node]].clear();
            }
            
            level++;

            
        }

        return -1;
    }
};