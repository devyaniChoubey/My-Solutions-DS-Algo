https://leetcode.com/problems/find-eventual-safe-states/description/

## any node which is part of a cycle can not be a safe node
## any node which leads to a cycle can not be a safe node


class Solution {
public:
    bool dfsCycle(int ver, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>& graph){
        vis[ver] = 1;
        pathVis[ver] = 1;

        for(auto it:graph[ver]){
           if(!vis[it]){
                if(dfsCycle(it, vis, pathVis, graph)){
                    return true;
                }
           }else if(pathVis[it] == 1 && vis[it] == 1) return true;
        }

        pathVis[ver] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>pathVis(n, 0);

        for(int i=0;i < n;i++){
            if(!vis[i]){
                dfsCycle(i, vis, pathVis, graph);
            }
        }

        vector<int>safeNodes;
        for(int i=0;i < n;i++){
            if(!pathVis[i]){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
