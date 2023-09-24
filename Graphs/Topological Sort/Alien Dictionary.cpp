https://leetcode.com/problems/alien-dictionary/description/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>>adj;

        unordered_map<char,int>inDegree;
        
        for(string word:words){
            for(char c:word){
                inDegree[c] = 0;
            }
        }


        for(int i=0;i < words.size() - 1;i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length() , s2.length());

            for(int j=0;j < len;j++){
                if(s1[j] != s2[j]){
                    if(adj[s1[j]].find(s2[j]) == adj[s1[j]].end()){
                        adj[s1[j]].insert(s2[j]);
                        inDegree[s2[j]]++;
                    }
                    break;
                }

                if (j == len - 1 and s1.size() > s2.size()) return "";
            }
        }

        queue<char>q;

        for(auto it:inDegree){
            if(it.second == 0) q.push(it.first);
        }

        string s = "";


        while(!q.empty()){
            char node = q.front();
            q.pop();

            s.push_back(node);

            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }


        if(inDegree.size() == s.length()) return s;
        else return "";

    }
};