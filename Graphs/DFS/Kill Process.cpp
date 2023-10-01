https://leetcode.com/problems/kill-process/description/

class Solution {
public:
    void dfs(int parent,vector<int>&result, unordered_map<int, vector<int>>&adj){
          
        for(auto child:adj[parent]){
            result.push_back(child);
            dfs(child, result, adj);
        }
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>>adj;

        for(int i=0;i < ppid.size();i++){
            if(ppid[i] > 0) adj[ppid[i]].push_back(pid[i]);
        }

        vector<int>result;
        result.push_back(kill);

        dfs(kill, result, adj);

        return result;
    }
};