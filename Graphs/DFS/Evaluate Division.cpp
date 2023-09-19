https://leetcode.com/problems/evaluate-division/description/

class Solution {
public:
    double dfs(string src, string dst, unordered_set<string>&vis, unordered_map<string, unordered_map<string , double>>&graph){ 
        if(src == dst) return 1.0;

        for(auto it:graph[src]){
            if(vis.count(it.first)) continue;

            vis.insert(it.first);

            double res = dfs(it.first, dst,vis, graph);

            if(res != -1.0) return res*it.second;
        }

        return -1.0;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string , double>>graph;

        for(int i=0;i < equations.size();i++){
            string x = equations[i][0] , y = equations[i][1];
            
            graph[x][y] = values[i];
            graph[y][x] = 1.0/values[i];
        }

        vector<double>ans(queries.size());

        for(int i=0;i < queries.size();i++){
            if(graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()){
                ans[i] = -1.00000;
            }else if(queries[i][0] == queries[i][1]){
                ans[i] = 1.00000;
            }else{
                unordered_set<string>vis;
                ans[i] = dfs(queries[i][0], queries[i][1],vis, graph);
            }
        }

        return ans;

    }
};