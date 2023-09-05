https://leetcode.com/problems/parallel-courses/description/


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int>adj[n+1];

        for(int i=0;i < relations.size();i++){
            int u = relations[i][0];
            int v = relations[i][1];

            adj[u].push_back(v);
        }

        vector<int>inDegree(n+1);

        for(int i=1;i <= n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }

        queue<int>q;

        for(int i=1;i <= n;i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        int semester = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i < size;i++){
                int node = q.front();
                q.pop();

                cnt++;

                for(auto it:adj[node]){
                    inDegree[it]--;
                    if(inDegree[it] == 0) q.push(it);
                }
            }
            semester++;
        }

        if(cnt == n) return semester;
        return -1;
    }
};