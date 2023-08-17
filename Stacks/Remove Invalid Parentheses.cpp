https://leetcode.com/problems/remove-invalid-parentheses/description/


// The idea is straightforward, with the input string s, we generate all possible states by removing one ( or ), check if they are valid, 
// if found valid ones on the current level, put them to the final result list and we are done, otherwise, add them to a queue and carry on to the next level.

// The good thing of using BFS is that we can guarantee the number of parentheses that need to be removed is minimal, also no recursion call is needed in BFS.



class Solution {
public:
    bool isValid(string &str){
        int cnt = 0;
        for(auto c:str){
            if(c == '(') cnt++;
            else if(c == ')'){
                cnt--;
                if(cnt < 0) return false;
            }
        }
        return (cnt == 0);
    }

    vector<string> removeInvalidParentheses(string s) {
        queue<string>q;
        q.push(s);
        map<string, int>vis;
        vis[s] = 1;

        vector<string>res;

        bool found = false;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                string temp = q.front();
                q.pop();
                
                if(isValid(temp)){
                    found = true;
                    res.push_back(temp);
                }

                if(found) continue;

                for(int i=0;i < temp.length();i++){
                    if(temp[i] == '(' || temp[i] == ')'){
                        string s2 = temp.substr(0, i) + temp.substr(i+1);
                        if(vis[s2]) continue;
                        q.push(s2);
                        vis[s2] = 1;
                    }
                }
                
            }

            if(found) break;
        }

        return res;
    }
};