https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string s) {
        stringstream ss(s);
        vector<string>p;
        deque<string>dq;
        string temp;

        while(getline(ss, temp, '/')){
            if(temp != "") p.push_back(temp);
        }

        for(int i=0;i < p.size();i++){
            if(p[i] == ".."){
                if(!dq.empty()) dq.pop_back();
            }else if(p[i] != ".." && p[i] != ".") dq.push_back(p[i]);
        }

        if(dq.empty()) return "/";

        string res;

        for(const string &str:dq){
            res += "/" + str;
        }

        return res;

    }
};