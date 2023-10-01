https://leetcode.com/problems/minimum-genetic-mutation/description/

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        queue<string>q;
        unordered_set<string>visited(bank.begin() , bank.end());

        if(visited.count(startGene)) visited.erase(startGene);
        q.push(startGene);

        if(startGene == endGene) return 0;

        int level = 1;
        while(!q.empty()){
            int size = q.size();
             
            for(int k=0;k < size;k++){
                string s = q.front();
                q.pop();

                for(int i=0;i < s.length();i++){
                    for(char c:"ACGT"){
                        string temp = s;
                        temp[i] = c;
                        if(visited.count(temp)){
                            if(temp == endGene) return level;
                            q.push(temp);
                            visited.erase(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};