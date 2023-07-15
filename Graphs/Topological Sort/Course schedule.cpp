https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i < prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>inDegree(numCourses , 0);
        queue<int>q;

        for(int i=0;i < numCourses;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }

        for(int i=0;i < numCourses;i++){
            if(inDegree[i] == 0) q.push(i);
        }

        int topoCnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoCnt++;

            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        if(topoCnt == numCourses) return true;
        return false;
        

    }
};