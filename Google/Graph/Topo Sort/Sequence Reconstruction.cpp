https://leetcode.com/problems/sequence-reconstruction/description/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<unordered_set<int>>adj(n+1, unordered_set<int>());
        vector<int>inDegree(n+1, 0);

        for(auto sequence:sequences){

            for(int i=0;i < sequence.size() - 1;i++){

                int u = sequence[i];
                int v = sequence[i+1];

                if(adj[u].count(v) == 0){
                    adj[u].insert(v);
                    inDegree[v]++;
                }
            }
        }

        queue<int>q;

        for(int i=1;i <= n;i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int>topo;

        while(!q.empty()){
            if(q.size() != 1) return false;

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        return (topo == nums);


    }
};