https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>&temp){
        temp.push_back(node);

        if(node == graph.size()-1) ans.push_back(temp);

        for(auto it:graph[node]){
            dfs(it,graph, ans,temp);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;

        int n = graph.size();
        
        dfs(0,graph, ans, temp);

        return ans;
    } 
};