
https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

https://leetcode.com/problems/time-needed-to-inform-all-employees/editorial/



//BFS
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n+1];

        for(int i=0;i < manager.size();i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>>q;

        q.push({headID, 0});

        int maxTime = 0;


        while(!q.empty()){
            int managerId = q.front().first;
            int time = q.front().second;
            
            maxTime = max(maxTime, time);

            q.pop();

            for(auto it:adj[managerId]){
                q.push({ it, informTime[managerId] + time});
            }
        }

        return maxTime;
    }
};


//DFS


class Solution {
public:
    void dfs(int headID, vector<int>adj[], vector<int>& informTime, int time,int &maxTime){
        
        for(auto it:adj[headID]){
            maxTime = max(maxTime, time + informTime[headID]);
            dfs(it, adj, informTime, time + informTime[headID],maxTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];

        for(int i=0;i < n;i++){
            if(manager[i] != -1)adj[manager[i]].push_back(i);
        }

        int maxTime = 0;

        dfs(headID, adj, informTime, 0, maxTime);

        return maxTime;
    }
};