https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        queue<string>q;
        unordered_set<string>vis(deadends.begin() , deadends.end());

        string start = "0000";

        if(vis.count(start)) return -1;
        if(start == target) return 0;

        q.push(start);
        vis.insert(start);

        int depth = 1;


        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                string node = q.front();
                q.pop();

                for(int i=0;i < 4;i++){
                    for(int d=-1;d <= 1;d+=2){
                        int y = ((node[i] - '0') + d + 10)%10;
                        string s = node.substr(0, i) + to_string(y) + node.substr(i+1);

                        if(s == target) return depth;

                        if(!vis.count(s)){
                            vis.insert(s);
                            q.push(s);
                        }
                    }
                }

            }

            depth++;
        }

        return -1;

    }
};