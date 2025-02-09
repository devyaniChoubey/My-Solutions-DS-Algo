https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    bool dfs(int node, int v, vector<int>adj[],vector<int>&vis){
        if(node == v) return true;

        vis[node] = 1;

        for(int adjNode:adj[node]){
            if(vis[adjNode]) continue;
            if(dfs(adjNode, v, adj,vis))return true;
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<int>adj[numCourses+1];

        for(int i=0;i < prerequisites.size();i++){
            int u = prerequisites[i][0] , v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<bool>ans;

        for(auto &query:queries){
            vector<int>vis(numCourses+1, 0);
            int u = query[0] , v = query[1];

            if(dfs(u, v,adj,vis)){
                ans.push_back(true);
            }else ans.push_back(false);
        }

        return ans;
    }
};