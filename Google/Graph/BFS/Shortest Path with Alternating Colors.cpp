https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
https://leetcode.com/problems/shortest-path-with-alternating-colors/editorial/


n = 5
redEdges = [[0,1],[1,2],[2,3],[3,4]]
blueEdges = [[1,2],[2,3],[3,1]]

output [0,1,2,3,7]


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>graph[n];
        queue<vector<int>>q;

        //in graph {adjNode, color}
        //1 for red color
        for(auto edge:redEdges){
            graph[edge[0]].push_back({edge[1], 1});
        }

        //0 for blue color
        for(auto edge:blueEdges){
            graph[edge[0]].push_back({edge[1], 0});
        }
        
        //{node, dist, color}
        q.push({0, 0, -1});

        vector<int>dist(n, -1);
        dist[0] = 0;

        while(!q.empty()){
            int node = q.front()[0];
            int steps = q.front()[1];
            int color = q.front()[2];
            q.pop();

            for(auto &it:graph[node]){
                int edgeColor = it[1];
                int adjNode = it[0];
                if(adjNode != -1 && edgeColor != color){
                    q.push({adjNode, steps + 1, edgeColor});
                    if(dist[adjNode] == -1) dist[adjNode] =  steps + 1;
                    it[0] = -1;
                }
            }
        }

        return dist;
    }
};