https://practice.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        
        for(int i=0;i < N - 1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            for(int j=0;j < min(s1.size(), s2.size());j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int>inDegree(K, 0);
        
        for(int i=0;i < K;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i < K;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
            
        }
        
        string s = "";
        
        for(auto it:ans){
            s += char(it + 'a');
        }
        
        
        return s;
        
    }
}